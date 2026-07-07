#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5, "none") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm(copy) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
        AForm::operator=(copy);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}
