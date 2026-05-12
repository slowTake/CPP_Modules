#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(10), energy(10), damage(0)
{
	std::cout << "Default Constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), damage(0)
{
	std::cout << "Named Constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called " << std::endl;
	this->name = copy.name;
	this->energy = copy.energy;
	this->damage = copy.damage;
	this->hp = copy.hp;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		std::cout << "Copy Assignment constructor called" << std::endl;
		this->name = copy.name;
		this->energy = copy.energy;
		this->damage = copy.damage;
		this->hp = copy.hp;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hp <= 0 || this->energy <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy or hp left to attack" << std::endl;
		return ;
	}
	this->energy -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ",causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
		return ;
	}
	if (amount >= this->hp)
		this->hp = 0;
	else
		this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! HP is now " << this->hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0 || this->energy == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair!" << std::endl;
		return ;
	}
	this->energy -= 1;
	this->hp += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! HP is now " << this->hp << std::endl;
}
