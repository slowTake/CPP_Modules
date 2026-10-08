#pragma once

#include <string>

// Static-only utility class: it stores nothing, so it must not be instantiable.
// All OCF members are private, so nobody outside the class can create,
// copy or destroy a ScalarConverter.
class ScalarConverter
{
    public:
        static void convert(const std::string& literal);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};
