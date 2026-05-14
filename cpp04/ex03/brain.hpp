#pragma once

#include "animal.hpp"

class brain
{
	private:
	 std::string _ideas[100];
	public:
	 brain();
	 brain(const brain &copy);
	 brain &operator=(const brain &copy);
	 ~brain();

	 std::string get_ideas(unsigned int index) const;
	 void set_ideas(std::string ideas, unsigned int index);
};