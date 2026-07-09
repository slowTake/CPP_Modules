#pragma once

#include <string>
#include <iostream>
#include <exception>

// Bureaucrat grade scale: 1 = highest rank, 150 = lowest rank
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade Shifting
    void incrementGrade();
    void decrementGrade();

    // Nested exceptions inherit std::exception so catch (std::exception &) works
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

// Ostream overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);