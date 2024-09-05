#include "../inc/Bureaucrat.hpp"

int	main(void) {
	{
		try {
			Bureaucrat	CEO(12, "CEO");
			std::cout << CEO << "\n";
		}
		catch(const std::exception& e) {
			std::cout << e.what() << '\n';
		}
		try {
			Bureaucrat	Supervisor(0, "Supervisor");
			std::cout << Supervisor << "\n";
		}
		catch(const std::exception& e) {
			std::cout << e.what() << '\n';
		}
		try {
			Bureaucrat	Worker(200, "Worker");
			std::cout << Worker;
		}
		catch(const std::exception& e) {
			std::cout << e.what() << '\n';
		}
	}
	std::cout << BLUE << "\n******************** PART 1 ********************\n\n";
	{
		try {
			Bureaucrat	CEO(1,"CEO");
			std::cout << "Pre-Increment:\n" << CEO << "\n";
			CEO.increment();
			std::cout << "Pos-Increment:\n" << CEO << "\n";
			std::cout << "Pre-Decrement:\n" << CEO << "\n";
			CEO.decrement();
			std::cout << "Pos-Decrement:\n" << CEO;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << BLUE << "\n******************** PART 2 ********************\n\n";
	{
		try {
			Bureaucrat	CEO(150, "CEO");
			std::cout << "Pre-Decrement:\n" << CEO << "\n";
			CEO.decrement();
			std::cout << "Pos-Decrement:\n" << CEO << "\n";
			std::cout << "Pre-Increment:\n" << CEO << "\n";
			CEO.increment();
			std::cout << "Pos-Increment:\n" << CEO;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << BLUE << "\n******************** PART 3 ********************\n\n";
	{
		try {
			Bureaucrat	CEO(50, "CEO");
			std::cout << "Pre-Increment:\n" << CEO << "\n";
			CEO.increment();
			std::cout << "Pos-Increment:\n" << CEO;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << BLUE << "\n******************** PART 4 ********************\n\n";
	{
		try {
			Bureaucrat	CEO(50, "CEO");
			std::cout << "Pre-Decrement:\n" << CEO << "\n";
			CEO.decrement();
			std::cout << "Pos-Decrement:\n" << CEO;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}