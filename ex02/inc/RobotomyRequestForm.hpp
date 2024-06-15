#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "./AForm.hpp"

# include <iostream>
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		
	public:
		/* ++ Orthodox Canonical Form ++ */
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		RobotomyRequestForm(std::string target);

		// Getters || Setters
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		std::string getTarget(void) const;

		void	execute(Bureaucrat const & executor) const;

};

// Stream Operators
std::ostream &operator<<(std::ostream& out, RobotomyRequestForm &r);

#endif