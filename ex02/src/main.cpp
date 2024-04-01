#include "../inc/FragTrap.hpp"

int main() {
	FragTrap p1("player1");
	FragTrap p2("player2");

	p1.getStats();
	std::cout << std::endl;

	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttack());
	p2.getStats();
	p1.highFivesGuys();
	std::cout << std::endl;

	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p1.getStats();
	std::cout << std::endl;

	p1.beRepaired(4);
	p1.getStats();
	std::cout << std::endl;

	std::cout << p1.getName() << " got a power boost!"<< std::endl;
	p1.setAttack(200);
	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttack());
	p2.getStats();
	p1.highFivesGuys();
	std::cout << std::endl;

	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p1.takeDamage(p2.getAttack());
	p1.getStats();
	std::cout << std::endl;

	p1.getEnergy();
	p1.setEnergy(0);
	p1.attack("player2");
}