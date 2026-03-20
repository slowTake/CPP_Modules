#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string result;
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.length(); j++)
			arg[j] = std::toupper(arg[j]);
		result += arg;
	}

	std::cout << result << std::endl;
	return (0);
}
