#include "../inc/ScavTrap.hpp"

int main() {

	ScavTrap p1("player1");
	ScavTrap p2("player2");

	p1.getAttack();
	p1.getHp();
	p1.getEnergy();
	std::cout << "\n";

	p1.attack(p2.getName());
	p2.guardGate();
	p2.takeDamage(p1.getAttack());
	p2.getHp();
	std::cout << "\n";

	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p1.getHp();
	std::cout << "\n";

	p1.beRepaired(4);
	p1.getHp();
	std::cout << "\n";

	std::cout << p1.getName() << " got a power boost!\n";
	p1.setAttack(40);
	p2.guardGate();
	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttack());
	p2.getHp();
	std::cout << "\n";

	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p1.takeDamage(p2.getAttack());
	p1.getHp();
	std::cout << "\n";

	p1.getEnergy();
	p1.setEnergy(0);
	p1.attack("player2");

	return (0);
}