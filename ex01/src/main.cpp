#include "../inc/Zombie.hpp"

int main() {

	Zombie	zombie;
	Zombie	*pZombie;

	pZombie = zombie.zombieHorde(1, "test");
	delete[] pZombie;
	pZombie = zombie.zombieHorde(5, "test5");
	delete[] pZombie;
	pZombie = zombie.zombieHorde(10, "test10");
	delete[] pZombie;

	return (0);
}