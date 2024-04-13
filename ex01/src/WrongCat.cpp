#include "../inc/WrongCat.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
WrongCat::WrongCat() {
	type = "Cat";
	std::cout << GREEN << "WrongCat Default Constructor Called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy_a) {
	WrongAnimal::operator=(copy_a);
	std::cout << GREEN << "WrongCat Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &copy)  : WrongAnimal() {
	*this = copy;
	std::cout << GREEN << "WrongCat Copy Constructor Called" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat Destructor Called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void	WrongCat::makeSound(void) {
	std::cout << type << " made a sound: Meow Meow" << std::endl;
}