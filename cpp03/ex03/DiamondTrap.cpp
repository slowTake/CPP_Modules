#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), name("default")
{
	this->hp = 100;
    this->energy = 50;
    this->damage = 30;
    std::cout << "DiamondTrap Default Constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->hp = FragTrap::hp;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout << "DiamondTrap " << this->name << " Constucted" << std::endl;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " and my ClapTrap parent is " << ClapTrap::name << std::endl;
}