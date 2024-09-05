#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
RobotomyRequestForm::RobotomyRequestForm() : _name("Robotomy Request"), _signGrade(72), _execGrade(45) {
	std::cout << GREEN << "RobotomyRequestForm Default Constructor Called\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _name(copy._name), _signGrade(72), _execGrade(45) {
	std::cout << GREEN << "RobotomyRequestForm Copy Constructor Called\n" << RESET;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED << "RobotomyRequestForm Destructor Called\n" << RESET;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target), _name("Robotomy Request"), _signGrade(72), _execGrade(45) {
	std::cout << GREEN << "RobotomyRequestForm Default Constructor Called\n" << RESET;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy_a) {
	std::cout << GREEN << "RobotomyRequestForm Copy Assignment Operator Called\n" << RESET;
	_signed = copy_a._signed;
	return (*this);
}

/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */
const std::string RobotomyRequestForm::getName(void) const {
	return(_name);
}

bool RobotomyRequestForm::getSigned(void) const {
	return(_signed);
}

int RobotomyRequestForm::getSignGrade(void) const {
	return (_signGrade);
}

int RobotomyRequestForm::getExecGrade(void) const {
	return (_execGrade);
}

std::string RobotomyRequestForm::getTarget(void) const {
	return(_target);
}
/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		AForm::execute(executor);
	}
	catch(const std::exception& e) {
		throw;
	}
	std::cout << GREEN << "RobotomyRequestForm is being executed..." << RESET << "\n";
	std::cout << "*******HEAVEN PIERCING DRILLING NOISES*******\n";
	srand((unsigned) time(NULL));
	if (rand() % 2)
		std::cout << getTarget() << "'s robotomy failed!\n";
	else
		std::cout << getTarget() << " has been robotomized!\n";
}

/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, RobotomyRequestForm &r) {
	out << r.getName() << " can only be signed by personnel with grade " << r.getSignGrade() << " or higher\n";
	out << " and it can only be executed by personnel with grade " << r.getExecGrade() << " or higher.\nThis document has a sign value of: " << std::boolalpha << r.getSigned() << "\n";
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */