#include "AForm.hpp"

static void validateGrade(int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm()
    : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150),
      _target("none") {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute,
             const std::string &target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute), _target(target)
{
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign),
      _gradeToExecute(copy._gradeToExecute), _target(copy._target) {}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return this->_name; }
bool AForm::getIsSigned() const { return this->_isSigned; }
int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExecute() const { return this->_gradeToExecute; }
std::string AForm::getTarget() const { return this->_target; }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    this->executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (Must be >= 1)";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (Must be <= 150)";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form '" << form.getName() << "', signed: "
        << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute()
        << ", target: " << form.getTarget() << ".";
    return out;
}
