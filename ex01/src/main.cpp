#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main(void) {
	{
		try {
			Bureaucrat	CEO(12, "CEO");
			Bureaucrat	Supervisor(1, "Supervisor");
			Form		Nda("Non-Disclosure Agreement");
			std::cout << CEO << "\n";
			std::cout << Supervisor << "\n";

			std::cout << Nda << "\n";
			CEO.signForm(Nda);

			std::cout << Nda << "\n";
			Supervisor.signForm(Nda);

			std::cout << Nda << "\n";
		}
		catch(const std::exception& e) {
			return (1);
		}
	}
	std::cout << YELLOW << "\n************************************************\n\n" << RESET;
	{
		try {
			Bureaucrat	CEO(0, "CEO-man");
			Bureaucrat	Supervisor(151, "Supervisor");
		}
		catch(const std::exception& e) {
			return (1);
		}
	}

	return (0);
}