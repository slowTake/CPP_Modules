#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon();
	Weapon(std::string name);
	~Weapon();
	std::string getType();
	void setType(std::string type);
};

#endif
