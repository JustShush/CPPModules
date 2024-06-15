#ifndef FORM_HPP
# define FORM_HPP

# include "./header.hpp"

# include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	/* ++ Orthodox Canonical Form ++ */
	Form();
	Form(const Form &copy);
	virtual ~Form();
	Form &operator=(const Form &t);
	/* ++ Orthodox Canonical Form ++ */

	Form(const std::string name);

	// Getters
	virtual const std::string getName(void) const;
	bool getSigned(void) const;
	virtual int getSignGrade(void) const;
	virtual int getExecGrade(void) const;

	// Setters
	void setSign(bool sign);

	void beSign(Bureaucrat &Bureaucrat);
	void checkGrade(Form &form);

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
std::ostream &operator<<(std::ostream& out, const Form &f);

#endif