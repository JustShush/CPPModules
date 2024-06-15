#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Form::Form() : _name("Default"), _signed(false), _signGrade(2), _execGrade(1) {
	std::cout << GREEN << "Form Default Constructor Called\n" << RESET;
	try {
		checkGrade(*this);	
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		throw;
	}
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(150), _execGrade(1) {
	std::cout << GREEN << "Form Copy Constructor Called\n" << RESET;
	*this = copy;
	try {
		checkGrade(*this);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		throw;
	}
}

Form::~Form() {
	std::cout << RED << "Form Destructor Called\n" << RESET;
}

Form& Form::operator=(const Form &t) {
	std::cout << GREEN << "Form Copy Assignment Operator Called\n" << RESET;
	_signed = t._signed;
	return (*this);
}

/* ++++++++++ Orthodox Canonical Form ++++++++++ */

Form::Form(const std::string name) : _name(name) , _signed(false), _signGrade(150), _execGrade(1) {
	std::cout << GREEN << "Form Name Default Constructor Called\n" << RESET;
	try {
		checkGrade(*this);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		throw;
	}
}

/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */
const std::string Form::getName() const {
	return _name;
}

bool Form::getSigned(void) const {
	return _signed;
}

int Form::getSignGrade(void) const {
	return _signGrade;
}

int Form::getExecGrade(void) const {
	return _execGrade;
}
/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */


/* /-/-/-/-/-/-/-/-/-/ Setters /-/-/-/-/-/-/-/-/-/ */
void Form::setSign(bool sign) {
	_signed = sign;
}
/* /-/-/-/-/-/-/-/-/-/ Setters /-/-/-/-/-/-/-/-/-/ */


void Form::beSign(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() > getSignGrade()) throw GradeTooLowException();
	else setSign(true);
}

void Form::checkGrade(Form &form) {
	if (form.getExecGrade() > 150 || form.getExecGrade() < 1) {
		std::cout << RED << "execGrade Error: " << RESET;
		if (form.getExecGrade() > 150) throw GradeTooLowException();
		throw GradeTooHighException();
	}
	if (form.getSignGrade() > 150  || form.getSignGrade() < 1) {
		std::cout << RED << "signGrade Error: " << RESET;
		if (form.getSignGrade() > 150) throw GradeTooLowException();
		throw GradeTooHighException();
	}
}


/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
const char	*Form::GradeTooHighException::what() const throw() {
	return("Out of range. Grade too high.");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return("Out of range. Grade too low.");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */


/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, const Form &f) {
	out << f.getName() << " can only be signed by personnel with grade " << f.getSignGrade() << " or higher.\n";
	out << "It can only be executed by personnel with grade " << f.getExecGrade() << " or higher.\n";
	out << "This document has a sign value of: " << std::boolalpha << f.getSigned() << "\n";
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */