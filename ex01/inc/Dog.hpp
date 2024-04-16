#ifndef DOG_HPP
# define DOG_HPP

# include "./header.hpp"

# include <iostream>
# include "./Animal.hpp"
# include "./Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain *brain;

	public:
		/* ++ Orthodox Canonical Form ++ */
		Dog();
		Dog(const Dog &_copy);
		~Dog();
		Dog&	operator=(const Dog &t);
		/* ++ Orthodox Canonical Form ++ */

		void	makeSound(void) const;
		Brain	*getBrain(void);

};

#endif