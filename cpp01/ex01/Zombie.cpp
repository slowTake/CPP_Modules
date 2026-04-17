#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::Zombie(void)
{
	this->_name = "Generic_Zombie";
}
Zombie::~Zombie(void)
{
	std::cout <<_name << " was destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << this-> _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

