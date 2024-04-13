#ifndef CAT_HPP
# define CAT_HPP

# include "./header.hpp"

# include <iostream>
# include "./Animal.hpp"

class	Cat : public Animal
{
	public:
		/* ++ Orthodox Canonical Form ++ */
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat&	operator=(const Cat &t);
		/* ++ Orthodox Canonical Form ++ */

		void	makeSound(void) const;
		Cat(std::string type);

};

#endif