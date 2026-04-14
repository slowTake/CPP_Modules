#include "PhoneBook.hpp"

bool	get_valid_input(std::string prompt, std::string &target)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, target))
			return (false);
		if (!target.empty())
			return (true);
		std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
}

int	main(void)
{
	PhoneBook phonebook;
	std::string cmd, f, l, n, p, s;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break ;

		if (cmd == "ADD")
		{
			if (!get_valid_input("Enter first name: ", f)
				|| !get_valid_input("Enter last name: ", l)
				|| !get_valid_input("Enter nickname: ", n)
				|| !get_valid_input("Enter phone number: ", p)
				|| !get_valid_input("Enter darkest secret: ", s))
				break ;

			Contact newContact;
			newContact.setContact(f, l, n, p, s);
			phonebook.addContact(newContact);
		}
		else if (cmd == "SEARCH")
		{
			phonebook.displayAll();
			phonebook.searchContact();
		}
		else if (cmd == "EXIT")
		{
			break ;
		}
	}
	return (0);
}
