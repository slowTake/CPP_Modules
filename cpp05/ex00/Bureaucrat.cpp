#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Validate grade before finishing construction; invalid grade = no object created
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy) {
        // _name is const, so it cannot be assigned. Only grade can be updated.
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->_name; }
int         Bureaucrat::getGrade() const { return this->_grade; }

// incrementGrade = promote (better rank); number goes DOWN because 1 is best
void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

// decrementGrade = demote (worse rank); number goes UP toward 150
void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

// what() messages are read by catch blocks via e.what()
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (Must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (Must be <= 150)";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
