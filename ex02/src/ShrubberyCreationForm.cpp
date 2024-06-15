#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

class AForm;

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
ShrubberyCreationForm::ShrubberyCreationForm() : _name("Shrubbery Request"), _signGrade(145), _execGrade(137) {
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor Called\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _name(copy._name), _signGrade(145), _execGrade(137) {
	std::cout << GREEN << "ShrubberyCreationForm Copy Constructor Called\n" << RESET;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED << "ShrubberyCreationForm Destructor Called\n" << RESET;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy_a) {
	std::cout << GREEN << "ShrubberyCreationForm Copy Assignment Operator Called\n" << RESET;
	_signed = copy_a._signed;
	return (*this);
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target  + ".shrubbery"), _name("Shrubbery Request"), _signGrade(145), _execGrade(137) {
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor Called\n" << RESET;
}

/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */
const std::string ShrubberyCreationForm::getName(void) const {
	return(_name);
}

bool ShrubberyCreationForm::getSigned(void) const {
	return(_signed);
}

int ShrubberyCreationForm::getSignGrade(void) const {
	return (_signGrade);
}

int ShrubberyCreationForm::getExecGrade(void) const {
	return (_execGrade);
}

const std::string ShrubberyCreationForm::getTarget(void) const {
	return(_target);
}
/* /+/+/+/+/+/+/+/+/+/ Getters /+/+/+/+/+/+/+/+/+/ */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	try {
		AForm::execute(executor);
	}
	catch(const std::exception& e) {
		throw;
		return ;
	}
	std::cout << GREEN << "ShrubberyCreationForm is being executed..." << RESET << "\n";
	std::ofstream	fileName(getTarget().c_str());
	if (!fileName.is_open()) {
		std::cout << "Open file error\n";
		return ;
	}
	for (int i = 0; i < 10; i++) {
		fileName << "                       ,@@@@@@@,\n               ,,,.   ,@@@@@@/@@,  .oo8888o.\n            ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n           ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n           %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n           %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n           `&%\\ ` /%&'    |.|        \\ '|8'\n               |o|        | |         | |\n               |.|        | |         | |\n           \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	}
	std::cout << getTarget() << " file created sucessfully!\n";
	fileName.close();
}

/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */
std::ostream &operator<<(std::ostream& out, ShrubberyCreationForm &s) {
	out << s.getName() << " can only be signed by personnel with grade " << s.getSignGrade() << " or higher\n";
	out << " and it can only be executed by personnel with grade " << s.getExecGrade() << " or higher.\nThis document has a sign value of: " << std::boolalpha << s.getSigned() << "\n";
	return out;
}
/* -+-+-+-+-+-+-+- Stream Operators -+-+-+-+-+-+-+- */