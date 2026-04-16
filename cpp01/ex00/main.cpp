#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating a random chump:" << std::endl;
	randomChump("Stack_zombie");

	std::cout << "\nCreating a head zombie:" << std::endl;
	Zombie* heapZombie = newZombie("Heap_Zombie");
	heapZombie->announce();

	delete heapZombie;

	return 0;
}
