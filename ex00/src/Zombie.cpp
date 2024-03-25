#include "../inc/Zombie.hpp"

Zombie::Zombie() {
	std::cout << GREEN << "new zombie\n" << RESET;
}

Zombie::~Zombie() {
	std::cout << ORANGE << _name << RED << " zombie deleted\n" << RESET;
}

void Zombie::announce(void) {
	std::cout << ORANGE << this->_name << RESET << ":  BraiiiiiiinnnzzzZ...\n";
}
