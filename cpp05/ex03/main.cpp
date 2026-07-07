#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Intern someRandomIntern;
    AForm *rrf;

    std::cout << "=== Test 1: Subject example ===" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat mechanic("Mechanic", 40);
        mechanic.signForm(*rrf);
        mechanic.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 2: Shrubbery creation ===" << std::endl;
    AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    if (shrub) {
        Bureaucrat gardener("Gardener", 130);
        gardener.signForm(*shrub);
        gardener.executeForm(*shrub);
        delete shrub;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 3: Presidential pardon ===" << std::endl;
    AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (pardon) {
        Bureaucrat president("President", 1);
        president.signForm(*pardon);
        president.executeForm(*pardon);
        delete pardon;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "=== Test 4: Unknown form ===" << std::endl;
    AForm *unknown = someRandomIntern.makeForm("coffee request", "Douglas");
    if (unknown)
        delete unknown;

    return 0;
}
