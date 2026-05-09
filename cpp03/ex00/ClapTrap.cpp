#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), damage(0)
{
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
}

ClapTrap::~ClapTrap()
{
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
}
