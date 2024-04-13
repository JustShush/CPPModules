#ifndef DOG_HPP
# define DOG_HPP

# include "./header.hpp"

# include <iostream>
# include "./Animal.hpp"

class	Dog : public Animal
{
	public:
		/* ++ Orthodox Canonical Form ++ */
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog&	operator=(const Dog &t);
		/* ++ Orthodox Canonical Form ++ */

		void	makeSound(void) const;
		Dog(std::string type);

};

#endif