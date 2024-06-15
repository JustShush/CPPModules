#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
AForm::AForm() : _name("Default"), _signed(false), _signGrade(2), _execGrade(1) {
	std::cout << GREEN << "AForm Default Constructor Called\n" << RESET;
	try {
		checkGrade(*this);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		throw;
	}
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(150), _execGrade(1) {
	std::cout << GREEN << "AForm Copy Constructor Called\n" << RESET;
	*this = copy;
	try {
		checkGrade(*this);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		throw;
	}
}

AForm::~AForm() {
	std::cout << RED << "AForm Destructor Called\n" << RESET;
}

AForm& AForm::operator=(const AForm &t) {
	std::cout << GREEN << "AForm Copy Assignment Operator Called\n" << RESET;
	_signed = t._signed;
	return (*this);
}

/* ++++++++++ Orthodox Canonical Form ++++++++++ */

AForm::AForm(const std::string name) : _name(name) , _signed(false), _signGrade(150), _execGrade(1) {
	std::cout << GREEN << "AForm Name Default Constructor Called\n" << RESET;
	try {
		checkGrade(*this);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		throw;
	}
}

/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */
const std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned(void) const {
	return _signed;
}

int AForm::getSignGrade(void) const {
	return _signGrade;
}

int AForm::getExecGrade(void) const {
	return _execGrade;
}
/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */


/* /-/-/-/-/-/-/-/-/-/ Setters /-/-/-/-/-/-/-/-/-/ */
void AForm::setSign(bool sign) {
	_signed = sign;
}
/* /-/-/-/-/-/-/-/-/-/ Setters /-/-/-/-/-/-/-/-/-/ */


void AForm::beSign(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() > getSignGrade()) throw GradeTooLowException();
	else setSign(true);
}

void AForm::checkGrade(AForm &form) {
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

void	AForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNSign();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
}

/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
const char	*AForm::GradeTooHighException::what() const throw() {
	return("Out of range. Grade too high.");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return("Out of range. Grade too low.");
}

const char	*AForm::FormNSign::what() const throw() {
	return(RED "Form was not signed!!" RESET);
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */


/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, const AForm &f) {
	out << f.getName() << " can only be signed by personnel with grade " << f.getSignGrade() << " or higher.\n";
	out << "It can only be executed by personnel with grade " << f.getExecGrade() << " or higher.\n";
	out << "This document has a sign value of: " << std::boolalpha << f.getSigned() << "\n";
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */