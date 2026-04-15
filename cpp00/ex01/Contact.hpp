#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact(void);
	~Contact(void);

	void setContact(std::string first, std::string last, std::string nick,
				std::string phone, std::string secret);
	void displayContact(void) const;
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
};

#endif
