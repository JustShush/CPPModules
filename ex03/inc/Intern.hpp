#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "../inc/PresidentialPardonForm.hpp"
# include "../inc/RobotomyRequestForm.hpp"
# include "../inc/ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:
		/* ++ Orthodox Canonical Form ++ */
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern& operator=(const Intern &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		AForm *returnPres(std::string target);
		AForm *returnShrub(std::string target);
		AForm *returnRobot(std::string target);
		AForm *makeForm(std::string name, std::string target);
};

#endif
