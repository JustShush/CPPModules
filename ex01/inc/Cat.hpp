#ifndef CAT_HPP
# define CAT_HPP

# include "./header.hpp"

# include <iostream>
# include "./Animal.hpp"
# include "./Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain *brain;

	public:
		/* ++ Orthodox Canonical Form ++ */
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat&	operator=(const Cat &t);
		/* ++ Orthodox Canonical Form ++ */

		void	makeSound(void) const;
		Brain getBrain(void);

};

#endif