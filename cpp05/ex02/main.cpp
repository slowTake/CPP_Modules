#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL))); // seed for RobotomyRequestForm 50% chance

    // Test 1: Sign + execute shrubbery; creates home_shrubbery file
    std::cout << "=== Test 1: Shrubbery creation ===" << std::endl;
    try {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("home");
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        std::cout << shrub << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 2: Robotomy request ===" << std::endl;
    try {
        Bureaucrat mechanic("Mechanic", 40);
        RobotomyRequestForm robo("Bender");
        mechanic.signForm(robo);
        mechanic.executeForm(robo);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 3: Presidential pardon ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur");
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    // Test 4: executeForm catches FormNotSignedException
    std::cout << "=== Test 4: Execute unsigned form ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        PresidentialPardonForm pardon("Ford");
        bob.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    // Test 5: can sign but exec grade too low (exec 137, bureaucrat grade 140)
    std::cout << "=== Test 5: Execute with grade too low ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 140);
        ShrubberyCreationForm shrub("office");
        intern.signForm(shrub);
        intern.executeForm(shrub);
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
