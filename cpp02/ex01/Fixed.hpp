#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		// Ortho Form
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();

		// New Constructors
		Fixed(const int n);
		Fixed(const float f);

		// Member Funcs
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
