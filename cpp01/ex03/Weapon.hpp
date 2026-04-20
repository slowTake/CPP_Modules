#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
	private:
		std::string type;
	
	public:
		Weapon();
		Weapon(std::string name);
		~Weapon();
		std::string getType();
		void setType(std::string type);
};

#endif