#pragma once

#include <exception>
#include <iostream>
#include <string>

// Forward declaration: Bureaucrat.hpp must not include AForm.hpp (avoids circular include)
class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form);
    void executeForm(AForm const &form) const; // const: executing a form does not change the bureaucrat

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
