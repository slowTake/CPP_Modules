#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45, "none") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45, target) {} // subject-required sign/exec grades

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
        AForm::operator=(copy);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRILLING NOISES *" << std::endl;

    // 50% success rate per subject; srand() called in main
    if (std::rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully"
                  << std::endl;
    else
        std::cout << "Robotomy of " << this->getTarget() << " failed" << std::endl;
}
