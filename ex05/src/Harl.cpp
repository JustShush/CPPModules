#include "../inc/Harl.hpp"

Harl::Harl() {
	std::cout << GREEN << "Harl Object Created" << RESET << "\n";
}

Harl::~Harl() {
	std::cout << RED << "Harl Object Destroyed" << RESET << "\n";
}

void	Harl::debug(void) {
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup ";
	std::cout <<	"burger. I really do!\n";
}

void	Harl::info(void) {
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You ";
	std::cout << "didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void) {
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void) {
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int		i;
	Harl	object;

	void	(Harl::*member_ptr[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
		};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			(object.*member_ptr[i])();
		i++;
	}
}
