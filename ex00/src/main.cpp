#include "../inc/ClapTrap.hpp"

int main() {

	ClapTrap p1("player1");
	ClapTrap p2("player2");
	
	p1.setAttack(2);
	p2.setAttack(3);
	p1.getStats();
	p2.getStats();

	std::cout << "\n";

	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttack());
	p2.getStats();
	std::cout << "\n";

	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p2.attack(p1.getName());
	p1.takeDamage(p2.getAttack());
	p1.getStats();;
	std::cout << "\n";

	p1.beRepaired(4);
	p1.getStats();
	std::cout << "\n";

	std::cout << p1.getName() << " got a power boost!\n";
	p1.setAttack(20);
	p1.attack(p2.getName());
	p2.takeDamage(p1.getAttack());
	p2.getStats();
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