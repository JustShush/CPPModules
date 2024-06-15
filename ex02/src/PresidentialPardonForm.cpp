#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
PresidentialPardonForm::PresidentialPardonForm() : _name("Presidential Pardon"), _signGrade(25), _execGrade(5) {
	std::cout << GREEN << "PresidentialPardonForm Default Constructor Called\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _name(copy._name), _signGrade(25), _execGrade(5) {
	std::cout << GREEN << "PresidentialPardonForm Copy Constructor Called\n" << RESET;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED << "PresidentialPardonForm Destructor Called\n" << RESET;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy_a) {
	std::cout << GREEN << "PresidentialPardonForm Copy Assignment Operator Called\n" << RESET;
	_signed = copy_a._signed;
	return (*this);
}

/* ++++++++++ Orthodox Canonical Form ++++++++++ */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target), _name("Presidential Pardon"), _signGrade(25), _execGrade(5) {
	std::cout << GREEN << "PresidentialPardonForm Default Constructor Called\n" << RESET;
}

/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */
const std::string PresidentialPardonForm::getName(void) const {
	return(_name);
}

bool PresidentialPardonForm::getSigned(void) const {
	return(_signed);
}

int PresidentialPardonForm::getSignGrade(void) const {
	return (_signGrade);
}

int PresidentialPardonForm::getExecGrade(void) const {
	return (_execGrade);
}

std::string PresidentialPardonForm::getTarget(void) const {
	return(_target);
}
/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	try {
		AForm::execute(executor);
	}
	catch(std::exception & e) {
		throw;
		return ;
	}
	std::cout << GREEN << "PresidentialPardonForm is being executed..." << RESET << "\n" << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}

/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, PresidentialPardonForm &p) {
	out << p.getName() << " can only be signed by personnel with grade " << p.getSignGrade() << " or higher\n";
	out << " and it can only be executed by personnel with grade " << p.getExecGrade() << " or higher.\nThis document has a sign value of: " << std::boolalpha << p.getSigned() << "\n";
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */