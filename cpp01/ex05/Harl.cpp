#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void(Harl::*complaints[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error 
	};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if(levels[i] == level)
		{
			(this->*complaints[i])();
			return;
		}
	}
	std::cout << "[Probably complaining about insignificant problems ]" << std::endl;
}