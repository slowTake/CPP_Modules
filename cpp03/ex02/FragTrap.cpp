#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
    this->hp = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap Constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "Copy constructor called " << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		std::cout << "Assignment operator called" << std::endl;
		this->name = copy.name;
		this->energy = copy.energy;
		this->damage = copy.damage;
		this->hp = copy.hp;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " is requesting a high five." << std::endl;
}
