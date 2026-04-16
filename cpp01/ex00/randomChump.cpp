#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie localZombie(name);
	localZombie.announce();
}
 