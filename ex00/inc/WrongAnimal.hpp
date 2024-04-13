#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "./header.hpp"

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal &copy_a);

		void	makeSound(void) const;
		std::string	getType(void) const;
		void		setType(std::string name);
};

#endif