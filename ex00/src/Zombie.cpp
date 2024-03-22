#include "../inc/Zombie.hpp"

Zombie::Zombie() {
	std::cout << "new zombie\n";
}

Zombie::~Zombie() {
	std::cout << _name << " zombie deleted\n";
}

void Zombie::announce(void) {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ...\n";
}
