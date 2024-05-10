#include "../inc/Bureaucrat.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Bureaucrat::Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
	std::cout << GREEN << "Copy Constructor Called\n" << RESET;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &t) {
	std::cout << GREEN << "Copy Assignment Operator Called" << RESET << "\n";
	this->_grade = t._grade;
	return (*this);
}

/* ++++++++++ Orthodox Canonical Form ++++++++++ */

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

int	Bureaucrat::myExeception(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (0);
}

void	Bureaucrat::increment(int grade)
{
	int	gradeBuf = _grade - grade;
	if (myExeception(gradeBuf)) return ;
	_grade - grade;
}

void	Bureaucrat::decrement(int grade)
{
	int	gradeBuf = _grade + grade;
	if (myExeception(gradeBuf)) return ;
	_grade + grade;
}

/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Out of range. Grade too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Out of range. Grade too low.");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */


/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, const Bureaucrat &b) {
	out << ORANGE << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET << std::endl;
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */