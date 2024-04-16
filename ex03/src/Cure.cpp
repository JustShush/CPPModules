#include "../inc/Cure.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Cure::Cure() {
	this->type = "cure";
	std::cout << GREEN << "Cure Default Constructor Called" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure &copy_a) {
	this->type = copy_a.type;
	std::cout << GREEN << "Cure Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

Cure::Cure(const Cure &copy) : AMateria() {
	*this = copy;
	std::cout << GREEN << "Cure Copy Constructor Called" << RESET << std::endl;
}

Cure::~Cure() {
	std::cout << RED << "Cure Destructor Called" << RESET << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void Cure::use(ICharacter& target) {
	(void)target;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria	*Cure::clone() const {
	AMateria *clone = new Cure;
	return(clone);
}
