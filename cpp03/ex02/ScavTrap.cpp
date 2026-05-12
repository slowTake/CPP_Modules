#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->hp = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap Constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "Copy constructor called " << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy or hp left to attack" << std::endl;
		return ;
	}
	this->energy -= 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ",causing " << damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}