#pragma once

#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _isSigned;              // false at construction; only mutable signing state
    const int _gradeToSign;
    const int _gradeToExecute;   // stored for ex02; unused when signing in ex01

public:
    // OCF
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    ~Form();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Signing
    void beSigned(const Bureaucrat &bureaucrat);

    // Custom Exception Classes
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

std::ostream &operator<<(std::ostream &out, const Form &form);
