#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), damage(0)
{
	std::cout << "Constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called " << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Assignment operator called" << std::endl;
	this->name = copy.name;
	this->energy = copy.energy;
	this->damage = copy.energy;
	this->hp = copy.hp;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy or hp left to attack";
		return ;
	}

	this->energy -= 1;
	std::cout << "ClapTrap " << this->name << " attacks" << target 
	<< ", causing" << damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->hp <= 0)
	{
		std::cout << "ClapTrap is already dead";	
		return;
	}

	if(this->hp > 0)
	{
		std::cout << "ClapTrap " << this->name << "took:" << this->damage << " Damage";
		this->hp -= this->hp - this->damage;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->hp <= 0 && this->energy == 0)
	{
		std::cout << "ClapTrap is already dead or out of energy" << std::endl;
		return;
	}
	if(this->hp > 0 && this->energy > 0)
	{
		std::cout << "something"; 
		this->hp += this->hp + amount;
	}
}
