#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "header.hpp"

# include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		void announce(void);
		Zombie	*zombieHorde(int N, std::string name);
};

#endif