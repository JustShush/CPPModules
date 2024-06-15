#ifndef AFORM_HPP
# define AFORM_HPP

# include "./header.hpp"

# include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	/* ++ Orthodox Canonical Form ++ */
	AForm();
	AForm(const AForm &copy);
	virtual ~AForm();
	AForm &operator=(const AForm &t);
	/* ++ Orthodox Canonical Form ++ */

	AForm(const std::string name);

	// Getters
	virtual const std::string getName(void) const;
	bool getSigned(void) const;
	virtual int getSignGrade(void) const;
	virtual int getExecGrade(void) const;

	// Setters
	void setSign(bool sign);

	void beSign(Bureaucrat &Bureaucrat);
	void checkGrade(AForm &form);

	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNSign : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

// Stream Operators
std::ostream &operator<<(std::ostream& out, const AForm &f);

#endif