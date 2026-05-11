#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap hero("George");
	ClapTrap hostile("James");
	hero.ClapTrap::attack("George");
	hostile.ClapTrap::takeDamage(5);
}
