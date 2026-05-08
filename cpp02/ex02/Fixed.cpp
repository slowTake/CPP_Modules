#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	this->_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		this->_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// New Member functions

Fixed::Fixed(const int n)
{
	this->_value = n << _bits;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _bits);
}

// Non member function
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

// Comparison ops
bool Fixed::operator>(const Fixed &rhs) const
{
	return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->_value != rhs.getRawBits();
}

// Math ops
Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());	
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());	
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());	
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());	
}

// Inc/Dec ops

Fixed &Fixed::operator++(void) 
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--(void) 
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}

// min/max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return(a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return(a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return(a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed&a, const Fixed &b)
{
	return(a > b) ? a : b;
}