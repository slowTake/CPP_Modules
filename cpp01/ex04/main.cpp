#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string ft_replace(std::string content, std::string s1, std::string s2)
{
	if(s1.empty())
		return content;

	std::string result;
	size_t pos = 0;
	size_t lastPos = 0;

	while((pos = content.find(s1, lastPos)) != std::string::npos)
	{
		result.append(content, lastPos, pos - lastPos);
		result += s2;
		lastPos = pos + s1.length();
	}
	result.append(content, lastPos);
	return result;
}

int main(int argc, char **argv)
{	
	if(argc != 4)
	{
		std::cout << "Please enter a ./FileName and two strings";
		return 1;
	}
	std::string outFileName = argv[1];
	std::ifstream inFile(argv[1]);
	
	if(!inFile.is_open())
	{
		std::cerr << "Error: File could not be opened" << std::endl;
		return 1;
	}
	std::stringstream buffer;
	buffer << inFile.rdbuf();
	std::string content = buffer.str();
	inFile.close();

	std::ofstream outputFile(outFileName + ".replace");
	if(outputFile.is_open())
	{
		std::string result = ft_replace(content, argv[2], argv[3]);
		outputFile << result;
		outputFile.close();
	}
	else
	{
		std::cerr << "Error: File could not be opened" << std::endl;
		return 1;
	}
	return 0;
}

