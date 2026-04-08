#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook phonebook;
	std::string command;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		if (command == "ADD")
		{
			std::cout << "Enter first name: ";
			std::getline(std::cin, firstName);
			// if(!std::cin)
				// break;
			std::cout << "Enter last name: ";
			std::getline(std::cin, lastName);
			// if(!std::cin)
			// 	break;
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phoneNumber);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);
			
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
		{
			break;
		}
	}
	
	return (0);
}
