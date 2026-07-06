#pragma once

#include "Bureaucrat.hpp"
class Form
{
private:
	const std::string _name;
	bool _unsigned;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExecute;
public:
	// OCF
	Form();
	Form(const std::string &name, bool _unsigned);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

};

std::ostream &operator<<(std::ostream &out, const Form &form);