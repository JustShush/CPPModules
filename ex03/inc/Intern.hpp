#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "../inc/PresidentialPardonForm.hpp"
# include "../inc/RobotomyRequestForm.hpp"
# include "../inc/ShrubberyCreationForm.hpp"

class Form;

class Intern
{
	public:
		/* ++ Orthodox Canonical Form ++ */
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern& operator=(const Intern &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		Form *returnPres(std::string target);
		Form *returnShrub(std::string target);
		Form *returnRobot(std::string target);
		Form *makeForm(std::string name, std::string target);
};

#endif
