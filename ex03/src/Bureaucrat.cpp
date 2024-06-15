#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
	std::cout << GREEN << "Copy Constructor Called\n" << RESET;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Destructor Called\n" << RESET;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &t) {
	std::cout << GREEN << "Copy Assignment Operator Called\n" << RESET;
	_grade = t._grade;
	return (*this);
}

/* ++++++++++ Orthodox Canonical Form ++++++++++ */

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name) {
	std::cout << GREEN << "Bureaucrat Grade Constructor Called\n" << RESET;
	myExeception(grade);
	_grade = grade;
	std::cout << "Valid grade\n";
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

int	Bureaucrat::myExeception(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (0);
}

void	Bureaucrat::increment(int grade) {
	int	gradeBuf = _grade - grade;
	if (myExeception(gradeBuf)) return ;
	_grade -= grade;
}

void	Bureaucrat::increment(void) {
	increment(1);
}

void	Bureaucrat::decrement(int grade) {
	int	gradeBuf = _grade + grade;
	if (myExeception(gradeBuf)) return ;
	_grade += grade;
}

void	Bureaucrat::decrement(void) {
	decrement(1);
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSign(*this);
	}
	catch(std::exception &e) {
		std::cout << getName() << RED << " couldn't sign " << RESET << form.getName() << " because " << e.what() << "\n";
	}
	if (form.getSigned())
		std::cout << getName() << GREEN << " signed " << RESET << form.getName() << "\n";
	
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
	}
	catch(std::exception & e) {
		std::cout << getName() << " could not execute " << form.getName() << " because " << e.what() << "\n";
		return ;
	}
	std::cout << YELLOW << getName() << " executed " << form.getName() << RESET << "\n\n";
}

/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return("Out of range. Grade too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return("Out of range. Grade too low.");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */


/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, const Bureaucrat &b) {
	out << ORANGE << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET << "\n";
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */