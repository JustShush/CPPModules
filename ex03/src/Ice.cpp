#include "../inc/Ice.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Ice::Ice() {
	this->type = "ice";
	std::cout << GREEN << "Ice Default Constructor Called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice &copy_a) {
	this->type = copy_a.type;
	std::cout << GREEN << "Ice Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

Ice::Ice(const Ice &copy) : AMateria() {
	*this = copy;
	std::cout << GREEN << "Ice Copy Constructor Called" << RESET << std::endl;
}

Ice::~Ice() {
	std::cout << RED << "Ice Destructor Called" << RESET << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone() const {
	AMateria *clone = new Ice;
	return(clone);
}