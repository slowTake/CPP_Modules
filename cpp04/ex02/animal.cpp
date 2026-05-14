#include "animal.hpp"
#include "brain.hpp"

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
    this->_brain = new brain();
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
        delete this->_brain;
        this->_brain = new brain(*copy._brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
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
    this->_brain = new brain();
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new brain(*copy._brain);
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
        delete this->_brain;
        this->_brain = new brain(*copy._brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
