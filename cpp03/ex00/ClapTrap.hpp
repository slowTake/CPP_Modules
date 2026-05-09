#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
#include <iostream>

class ClapTrap
{
  private:
	std::string name;
	unsigned int hp = 10;
	unsigned int energy = 10;
	unsigned int damage = 0;

  public:
	// Ortho
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	// Member functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif
