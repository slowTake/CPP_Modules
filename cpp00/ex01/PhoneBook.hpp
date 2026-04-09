#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  private:
	static const int 	MAX_CONTACTS = 8;
	Contact 			contacts[MAX_CONTACTS];
	int 				contactCount = 0;
	int 				oldestIndex = 0;

  public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(Contact contact);
	void searchContact(void);
	void displayAll(void) const;
};

#endif
