#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	_name = name;
	std::cout << GREEN << "New HumanA created " << name << RESET << "\n";
}

HumanA::~HumanA() {
	std::cout << RED << _name << " just died!" << RESET << "\n";
}

void	HumanA::attack() {
	std::cout << ORANGE << _name << RESET << " attacks with their " << YELLOW << _weapon.getType() << RESET << "\n";
}

void	HumanA::setWeapon(Weapon weapon) {
	_weapon = weapon;
}