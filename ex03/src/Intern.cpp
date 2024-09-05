#include "../inc/Intern.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Intern::Intern() {
	std::cout << GREEN << "Intern Default Constructor Called" << RESET << "\n";
}

Intern::Intern(const Intern &copy) {
	std::cout << GREEN << "Intern Copy Constructor Called" << RESET << "\n";
	*this = copy;
}

Intern::~Intern() {
	std::cout << RED << "Intern Destructor Called" << RESET << "\n";
}

Intern& Intern::operator=(const Intern &copy_a) {
	std::cout << GREEN << "Intern Copy Assignment Operator Called" << RESET << "\n";
	(void)copy_a;
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

AForm	*Intern::returnPres(std::string target) {
	std::cout << "Intern creates " << target << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::returnShrub(std::string target) {
	std::cout << "Intern creates " << target << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::returnRobot(std::string target) {
	std::cout << "Intern creates " << target << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	AForm*	(Intern::*member_ptr[3])(std::string target) = {
		&Intern::returnPres,
		&Intern::returnRobot,
		&Intern::returnShrub
	};

	std::string	forms[3] = {
			"presidential pardon",
			"robotomy creation",
			"shrubbery request"
		};

	for (int i = 0; i < 3; i++) 	{
		if (name.compare(forms[i]) == 0)
			return ((this->*member_ptr[i])(target));
	}
	std::cout << "There is no Form called " << name << "\n";
	return (NULL);
}