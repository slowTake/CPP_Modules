#include "Weapon.hpp"

class HumanA
{
	private:
		
	public:
		HumanA();
		HumanA(std::string name);
		~HumanA();
		void attack()
		{
			std::cout << "attacks with their " << Weapon.getType() << std::endl;
		}
};

//HumanA is ref
//HumanB is pointer

//ref cannot be null
//