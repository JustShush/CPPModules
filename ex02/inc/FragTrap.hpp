#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);

		~FragTrap();
		FragTrap& operator=(const FragTrap &copy_a);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif