#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include "./header.hpp"

# include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	/* ++ Orthodox Canonical Form ++ */
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &t);
	/* ++ Orthodox Canonical Form ++ */

	Bureaucrat(int grade, const std::string name);

	// Getters || Setters
	const std::string getName() const;
	int getGrade() const ;

	int myExeception(int grade);

	void increment(int grade);
	void increment(void);
	void decrement(int grade);
	void decrement(void);

	void signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

//
std::ostream &operator<<(std::ostream& out, const Bureaucrat &b);

#endif