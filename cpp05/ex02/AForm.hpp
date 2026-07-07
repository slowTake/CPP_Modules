#pragma once

#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;

    virtual void executeAction() const = 0;

protected:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute,
          const std::string &target);

public:
    AForm(const AForm &copy);
    AForm &operator=(const AForm &copy);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string getTarget() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const &executor) const;

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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
