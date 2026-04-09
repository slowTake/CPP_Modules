#include "PhoneBook.hpp"
// #include "contact.cpp"
#include <iostream>
#include <string>

bool getInput(std::string cmd, std::string &target)
{
	std::cout << cmd;
	if(!(std::getline(std::cin, target)))
		return false;
	if(target.empty())
		std::cout << "Field Empty!" << std::endl;
	return true;
}

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		if(!getInput("Enter command (ADD, SEARCH, EXIT): ", command))
			break;

		if(command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			if(!getInput("First name: ", firstName) || !getInput("Last name: ", lastName) 
			||!getInput("Nickname: ", nickname) ||!getInput("Phone Number: ", phoneNumber) 
			||!getInput("Darkest Secret: ", darkestSecret))
				break;
			Contact newContact;
			newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phonebook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			phonebook.displayAll();
			phonebook.searchContact();
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}
