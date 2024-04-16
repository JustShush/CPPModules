#include "../inc/AMateria.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
AMateria::AMateria() {
	std::cout << GREEN << "AMateria Default Constructor Called" << RESET << std::endl;
}

AMateria::AMateria(std::string const &_type) {
	this->type = _type;
}

AMateria& AMateria::operator=(const AMateria &copy_a) {
	this->type = copy_a.type;
	std::cout << GREEN << "AMateria Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
	std::cout << GREEN << "AMateria Copy Constructor Called" << RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << RED << "AMateria Destructor Called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

std::string const &AMateria::getType() const {
	return(this->type);
}

void	AMateria::setType(std::string const &type) {
	this->type = type;
}

void	AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "Default Use" << std::endl;
}