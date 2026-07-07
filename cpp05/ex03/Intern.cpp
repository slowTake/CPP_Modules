#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

typedef AForm *(*FormCreator)(const std::string &target);

struct FormEntry
{
    const char *name;
    FormCreator create;
};

static const FormEntry formTable[] = {
    {"shrubbery creation", &createShrubbery},
    {"robotomy request", &createRobotomy},
    {"presidential pardon", &createPresidential},
};

static const std::size_t formTableSize = sizeof(formTable) / sizeof(formTable[0]);

Intern::Intern() {}

Intern::Intern(const Intern &copy) { (void)copy; }

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    for (std::size_t i = 0; i < formTableSize; ++i) {
        if (formName == formTable[i].name) {
            AForm *form = formTable[i].create(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Error: form name \"" << formName << "\" does not exist"
              << std::endl;
    return NULL;
}
