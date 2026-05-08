#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// New Member functions

Fixed::Fixed(const int n)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_value = n << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float Constructor called" << std::endl;
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

/* 
Insertion operator overload
Converted to a float then sent to stream
return to stream 
*/

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
