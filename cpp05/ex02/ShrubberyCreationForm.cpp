#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137, "none") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137, target) {} // subject-required sign/exec grades

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
        AForm::operator=(copy);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    // Only runs after AForm::execute() confirms signed + grade OK
    // Writes runtime output file <target>_shrubbery (not a build artifact)
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Could not open shrubbery file");

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();
}
