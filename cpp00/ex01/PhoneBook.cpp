#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) : contactCount(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(Contact contact)
{
	if (contactCount < MAX_CONTACTS)
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
	else
	{
		std::cout << "PhoneBook is full!" << std::endl;
	}
}

void PhoneBook::searchContact(void)
{
	int index;
	
	std::cout << "Enter contact index: ";
	std::cin >> index;
	if (index >= 0 && index < contactCount)
		contacts[index].displayContact();
	else
		std::cout << "Invalid index!" << std::endl;
}

void PhoneBook::displayAll(void) const
{
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "Index " << i << ": ";
		std::cout << contacts[i].getFirstName() << " ";
		std::cout << contacts[i].getLastName() << " ";
		std::cout << contacts[i].getNickname() << std::endl;
	}
}
