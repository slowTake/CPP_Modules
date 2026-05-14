#include "animal.hpp"

/* ~~~   Animal   ~~~ */

animal::animal() : type("animal")
{
	std::cout << "Animal Constructed" << std::endl;
}

animal::animal(const animal &copy)
{
	*this = copy;
	std::cout << "Animal copy constructor" << std::endl;
}

animal &animal::operator=(const animal &copy)
{
	if(this != &copy)
		this->type = copy.type;
	return *this;
}

animal::~animal()
{
	std::cout << "animal destructor" << std::endl;
}

void animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

std::string animal::getType() const
{
	return this->type;
}


/* ~~~   Doggo   ~~~ */

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

/* ~~~   Catto   ~~~ */

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
