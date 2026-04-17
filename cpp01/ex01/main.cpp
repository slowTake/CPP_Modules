#include "Zombie.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Please enter a number" << std::endl;
		return 1;
	}
	
	std::string arg = argv[1];
	for(size_t i = 0; i < arg.length(); i++)
	{
		if(!std::isdigit(arg[i]))
		{
			std::cout << "Error: Enter a positive integer" << std::endl;
			return (1);
		}
	}

	int N = std::stoi(arg);
	if(N <= 0)
	{
		std::cout << "Error: Horde too small" << std::endl;
		return 1;
	}

	Zombie* horde = zombieHorde(N, "Chomper");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde;

	return 0;
}
