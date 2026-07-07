#pragma once

#include <string>

class AForm;

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target);
};
