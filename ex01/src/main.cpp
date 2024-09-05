#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void) {

	Bureaucrat CEO(12, "CEO");
	Bureaucrat Supervisor(1, "Supervisor");
	Form Nda("Non-Disclosure Agreement");
	std::cout << CEO << std::endl;
	std::cout << Supervisor << std::endl;

	std::cout << Nda << std::endl;
	CEO.signForm(Nda);

	std::cout << Nda << std::endl;
	Supervisor.signForm(Nda);

	std::cout << Nda << std::endl;

	return (0);
}