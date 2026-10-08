#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <iomanip>

// ---------------------------------------------------------------------------
// OCF (private, never used: the class cannot be instantiated)
// ---------------------------------------------------------------------------

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// ---------------------------------------------------------------------------
// Helpers (static = only visible inside this file)
// ---------------------------------------------------------------------------

enum LiteralType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO_FLOAT,
    TYPE_PSEUDO_DOUBLE,
    TYPE_INVALID
};

static const int FLOAT_DIGITS = std::numeric_limits<float>::digits10;   // 6
static const int DOUBLE_DIGITS = std::numeric_limits<double>::digits10; // 15

// NaN is the only value that is not equal to itself (std::isnan is C++11)
static bool isNan(double d)
{
    return d != d;
}

static bool isInf(double d)
{
    return d == std::numeric_limits<double>::infinity()
        || d == -std::numeric_limits<double>::infinity();
}

// Checks "[+-]digits[.digits]" in decimal notation.
// needDot: true for float/double literals, false for int literals.
static bool isDecimal(const std::string& s, bool needDot)
{
    size_t i = 0;
    bool digits = false;
    bool dot = false;

    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        i++;
    for (; i < s.length(); i++)
    {
        if (std::isdigit(static_cast<unsigned char>(s[i])))
            digits = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    return digits && dot == needDot;
}

static LiteralType detectType(const std::string& s)
{
    if (s.empty())
        return TYPE_INVALID;
    if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
        return TYPE_PSEUDO_FLOAT;
    if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
        return TYPE_PSEUDO_DOUBLE;
    // 'c' with quotes, or a single non-digit character like c
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return TYPE_CHAR;
    if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
        return TYPE_CHAR;
    if (isDecimal(s, false))
        return TYPE_INT;
    if (s[s.length() - 1] == 'f' && isDecimal(s.substr(0, s.length() - 1), true))
        return TYPE_FLOAT;
    if (isDecimal(s, true))
        return TYPE_DOUBLE;
    return TYPE_INVALID;
}

// Formats a floating value.
// - Whole numbers (that are not huge) are shown in fixed notation with
//   one decimal, so 42 becomes "42.0".
// - Other values use `precision` significant digits. The caller chooses
//   the precision of the ORIGINAL type, so 4.2f shows as 4.2 in the
//   double line too, instead of exposing float rounding (4.19999980926514).
static std::string formatFloating(double d, int precision)
{
    std::ostringstream oss;
    if (d == std::floor(d) && std::fabs(d) < 1e16)
        oss << std::fixed << std::setprecision(1) << d;
    else
        oss << std::setprecision(precision) << d;
    return oss.str();
}

// ---------------------------------------------------------------------------
// Printers. Each one receives the value as a double (every scalar type
// fits exactly in a double) and explicitly casts it to its target type.
// ---------------------------------------------------------------------------

static void printChar(double d)
{
    std::cout << "char: ";
    if (isNan(d) || isInf(d)
        || d < std::numeric_limits<char>::min()
        || d > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else
    {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
}

static void printInt(double d)
{
    std::cout << "int: ";
    if (isNan(d) || isInf(d)
        || d < std::numeric_limits<int>::min()
        || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
    std::cout << "float: ";
    if (isNan(d))
        std::cout << "nanf" << std::endl;
    else if (isInf(d))
        std::cout << (d > 0 ? "+inff" : "-inff") << std::endl;
    // max() is the biggest finite float; anything bigger would overflow
    else if (d > std::numeric_limits<float>::max()
        || d < -std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << formatFloating(static_cast<float>(d), FLOAT_DIGITS) << "f" << std::endl;
}

static void printDouble(double d, int precision)
{
    std::cout << "double: ";
    if (isNan(d))
        std::cout << "nan" << std::endl;
    else if (isInf(d))
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << formatFloating(d, precision) << std::endl;
}

// precision = significant digits of the SOURCE type, used for the double line
// (the float line always uses float precision)
static void printAll(double d, int precision)
{
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d, precision);
}

static void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

// ---------------------------------------------------------------------------
// convert: 1) detect the type, 2) convert the string to that actual type,
//          3) convert that value explicitly to the other types and print.
// ---------------------------------------------------------------------------

void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = detectType(literal);

    switch (type)
    {
        case TYPE_CHAR:
        {
            char c = (literal.length() == 3) ? literal[1] : literal[0];
            printAll(static_cast<double>(c), FLOAT_DIGITS);
            break;
        }
        case TYPE_INT:
        {
            errno = 0;
            long l = std::strtol(literal.c_str(), NULL, 10);
            if (errno == ERANGE
                || l < std::numeric_limits<int>::min()
                || l > std::numeric_limits<int>::max())
            {
                // Too big for an int: keep going as a double so the
                // float/double lines can still be shown.
                printAll(std::strtod(literal.c_str(), NULL), DOUBLE_DIGITS);
                break;
            }
            int i = static_cast<int>(l);
            printAll(static_cast<double>(i), FLOAT_DIGITS);
            break;
        }
        case TYPE_FLOAT:
        case TYPE_PSEUDO_FLOAT:
        {
            // strtod stops at the trailing 'f' (and understands nan/inf)
            double raw = std::strtod(literal.c_str(), NULL);
            if (!isInf(raw) && !isNan(raw)
                && (raw > std::numeric_limits<float>::max()
                    || raw < -std::numeric_limits<float>::max()))
            {
                printImpossible();
                break;
            }
            float f = static_cast<float>(raw);
            printAll(static_cast<double>(f), FLOAT_DIGITS);
            break;
        }
        case TYPE_DOUBLE:
        case TYPE_PSEUDO_DOUBLE:
        {
            errno = 0;
            double d = std::strtod(literal.c_str(), NULL);
            if (errno == ERANGE && isInf(d))
            {
                printImpossible();
                break;
            }
            printAll(d, DOUBLE_DIGITS);
            break;
        }
        default:
            std::cout << "Error: invalid literal \"" << literal << "\"" << std::endl;
            printImpossible();
    }
}
