#include "../inc/Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
	int i = 0;
	Zombie *pZombie;

	pZombie = new Zombie[N];

	while (i < N) {
		pZombie[i]._name = name;
		pZombie[i].announce();
		i++;
	}
	return (pZombie);
}
