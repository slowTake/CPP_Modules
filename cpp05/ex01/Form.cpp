#include "Form.hpp"

static void validateGrade(int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form()
    : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form &copy)
    : _name(copy._name),
      _isSigned(copy._isSigned),
      _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute) {}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return this->_name; }
bool Form::getIsSigned() const { return this->_isSigned; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExecute() const { return this->_gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (Must be >= 1)";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (Must be <= 150)";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form '" << form.getName() << "', signed: "
        << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << ".";
    return out;
}
