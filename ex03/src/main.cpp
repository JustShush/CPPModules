#include <iostream>
#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int	main() {

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		//! [IMPORTANT]: idk if this is correct but if i try to attack before setting the weapon it prints some random chars
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return (0);
}

/*
 * When to use pointers or Ref
 * 
 * Ref:
 * - You want to alias an existing object.
 * - You want to avoid the syntax of pointers (* and ->).
 * - You don't need reassignment after initialization.
 * - You want to ensure that the reference always refers to a valid object (no null references).
 * - You want to pass parameters to functions without copying the objects (avoiding the overhead of copying large objects).
 * 
 * Pointers:
 * - You need reassignable or nullable references.
 * - You want to dynamically allocate memory (with new) or interact with C-style interfaces.
 * - You want to implement data structures like linked lists, trees, etc.
 * - You're dealing with function parameters where you might not always have a value to pass (you can use null pointers to represent "no value").
*/