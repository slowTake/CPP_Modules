#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "mem address of string variable: " << &str << std::endl;
	std::cout << "mem address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "mem address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "value of string variable: " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value refered to by stringREF: " << stringREF << std::endl;
	
	return 0;
}
