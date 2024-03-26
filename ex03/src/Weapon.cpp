#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {}

void	Weapon::setType(std::string type) {
	_type = type;
	std::cout << "The new type of Weapon is: \'" << type << "\'\n";
}

const std::string	&Weapon::getType(void) {
	return (_type);
}
