#include "../inc/Zombie.hpp"

int main() {

	Zombie	zombie;
	Zombie	*pZombie;

	pZombie = zombie.newZombie("Foo");
	zombie.randomChump("RANDOM_CHUMP");

	delete pZombie;
	
	return (0);
}