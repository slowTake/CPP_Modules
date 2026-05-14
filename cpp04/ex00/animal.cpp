#include "animal.hpp"

/*
~~~   Animal   ~~~
*/

animal::animal()
{
	std::cout << "Animal Constructor" << std::endl;
}

animal::animal(const animal &copy)
{
	std::cout << "Animal copy constructor" << std::endl;
}

animal &animal::operator=(const animal &copy)
{
	std::cout << "animal assignment operator" << std::endl;
}

animal::~animal()
{
	std::cout << "animal destructor" << std::endl;
}


/*
~~~   Doggo   ~~~
*/

Dog::Dog()
{
	std::cout << "doggo Constructor" << std::endl;
}
Dog::Dog(const Dog &copy)
{

}
Dog &operator=(const Dog &copy)
{

}

~Dog()
{

}

/*
~~~   Catto   ~~~
*/