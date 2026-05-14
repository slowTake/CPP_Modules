#include "brain.hpp"

brain::brain()
{
	std::cout << "brain Default constructor called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";	
}

brain::~brain()
{
	std::cout << "brain Destructor called\n";
}

brain::brain(const brain &copy)
{
	std::cout << "brain Copy constructor called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];	
}

brain &brain::operator=(const brain &copy)
{
	std::cout << "brain Copy assignment operator called\n";
	if (this != &copy){
		for (int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	}
	return *this;
}

std::string	brain::get_ideas(unsigned int index) const
{
	if(index < 100)
		return _ideas[index];
	return "";
}

void	brain::set_ideas(std::string ideas, unsigned int index)
{
	if (index < 100)	
		_ideas[index] = ideas;
}
