#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "./AForm.hpp"

# include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		/* ++ Orthodox Canonical Form ++ */
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		PresidentialPardonForm(std::string target);

		// Getters || Setters
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		std::string getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;
};

// Stream Operators
std::ostream &operator<<(std::ostream& out, PresidentialPardonForm &p);

#endif