#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int	main(void)
{
	{
		Bureaucrat	FBI(75, "FBI-man");
		Bureaucrat	Boss(1, "Boss-man");
		Bureaucrat	Intern(150, "John");

		PresidentialPardonForm	President("Captain");
		RobotomyRequestForm		Robot("Lagann");
		ShrubberyCreationForm	Shrub("Home");

		std::cout << FBI << "\n";
		std::cout << Boss << "\n";
		std::cout << President << "\n";

		Boss.signForm(President);
		Boss.signForm(Robot);
		Boss.signForm(Shrub);

		std::cout << "\n";

		Intern.executeForm(President);
		Intern.executeForm(Robot);
		Intern.executeForm(Shrub);

		std::cout << "\n";

		FBI.executeForm(President);
		FBI.executeForm(Robot);
		FBI.executeForm(Shrub);

		std::cout << "\n";

		Boss.executeForm(President);
		Boss.executeForm(Robot);
		Boss.executeForm(Shrub);
	}
	return (0);
}