#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _value;
	static const int _bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();

	void setRawBits(int const raw);
	int getRawBits(void) const;
};

#endif
