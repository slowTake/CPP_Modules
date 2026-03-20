#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::setContact(std::string first, std::string last, std::string nick,
						std::string phone, std::string secret)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

void Contact::displayContact(void) const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::getFirstName(void) const
{
	return (firstName);
}

std::string Contact::getLastName(void) const
{
	return (lastName);
}

std::string Contact::getNickname(void) const
{
	return (nickname);
}
