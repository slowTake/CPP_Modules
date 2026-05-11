#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap hero("George");
	ClapTrap hostile("James");
	hero.ClapTrap::attack("James");
	hostile.ClapTrap::takeDamage(5);
}
