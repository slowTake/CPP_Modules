#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int contactCount;
	int nextIndex = 0;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(const Contact& contact);
	void searchContact(void);
	void displayAll(void) const;
};

#endif
