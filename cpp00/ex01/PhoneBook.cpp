#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : contactCount(0), nextIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(const Contact& contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;

	if(contactCount < MAX_CONTACTS)
	{
		contactCount++;
	}
}

void PhoneBook::searchContact(void)
{
	int	index;

	std::string input;
	index = -1;
	if (contactCount == 0)
	{
		std::cout << "Empty phonebook" << std::endl;
		return ;
	}
	while (true)
	{
		std::cout << "Enter contact index: ";
		if (!std::getline(std::cin, input))
			return ;
		try
		{
			index = std::stoi(input);
			if (index >= 0 && index < contactCount)
			{
				contacts[index].displayContact();
				break ;
			}
			else
			{
				std::cout << "Error: Index out of range." << std::endl;
			}
		}
		catch (...)
		{
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
		}
	}
}

void PhoneBook::displayAll(void) const
{
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << contacts[i].getFirstName();
		std::cout << "|" << std::setw(10) << contacts[i].getLastName();
		std::cout << "|" << std::setw(10) << contacts[i].getNickname(); 
		std::cout << "|" << std::endl;
	}
}
