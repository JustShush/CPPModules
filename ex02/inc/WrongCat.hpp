#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "./header.hpp"

# include <iostream>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat& operator=(const WrongCat &copy_a);

		void	makeSound(void);
};

#endif