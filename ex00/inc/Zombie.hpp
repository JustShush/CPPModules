#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "header.hpp"

# include <iostream>

class Zombie
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNbr;
		std::string darkS;
	public:
		Zombie();
		~Zombie();
};

#endif