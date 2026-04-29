#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;

	public:
		// default constructor
		Fixed(); 

		// copy constructor
		Fixed(const Fixed &copy);

		// copy assignment operator
		Fixed &operator=(const Fixed &copy);
		
		//destructor
		~Fixed();
};

#endif
