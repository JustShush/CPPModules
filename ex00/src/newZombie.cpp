#include "../inc/Zombie.hpp"

Zombie	*Zombie::newZombie(std::string name) {
	Zombie	*newZombie;

	newZombie = new Zombie;
	newZombie->_name = name;

	(*newZombie).announce();
	return (newZombie);
}
