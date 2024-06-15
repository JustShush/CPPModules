#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# include <iostream>
# include <fstream>
# include <cstring>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		
	public:
		/* ++ Orthodox Canonical Form ++ */
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		ShrubberyCreationForm(std::string target);

		// Getters || Setters
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		const std::string getTarget(void) const;

		void	execute(Bureaucrat const & executor) const;
};

// Stream Operators
std::ostream &operator<<(std::ostream& out, ShrubberyCreationForm &s);

#endif