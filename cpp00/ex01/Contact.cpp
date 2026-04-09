#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void PhoneBook::searchContact(void)
{
    std::string input;

    if (contactCount == 0) 
	{
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "Enter contact index: ";
    if (!(std::getline(std::cin, input)) || input.empty())
        return;

    try
	{
        int index = std::stoi(input);

        if (index >= 0 && index < contactCount) {
            contacts[index].displayContact();
        } else {
            std::cout << "Error: Index out of range (0-" << contactCount - 1 << ")." << std::endl;
        }
    } 
    catch (const std::invalid_argument& e) 
	{
        std::cout << "Error: That's not a number!" << std::endl;
    } 
    catch (const std::out_of_range& e) 
	{
        std::cout << "Error: Number is way too large!" << std::endl;
    }
}