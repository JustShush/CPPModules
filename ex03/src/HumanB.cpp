#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	std::cout << GREEN << "New HumanB created " << name << RESET << "\n";
}

HumanB::~HumanB() {
	std::cout << RED << _name << " just died!" << RESET << "\n";
}

void	HumanB::attack() {
	if (_weapon)
		std::cout << ORANGE << _name << RESET << " attacks with their " << YELLOW << _weapon->getType() << RESET << "\n";
	else
		std::cout << ON_YELLOW << _name << " doesn't have a  weapon!!!" << RESET << "\n";
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}