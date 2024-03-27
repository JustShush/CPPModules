#ifndef FIXED_HPP
# define FIXED_HPP

# include "./header.hpp"

#include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	bit = 8;

	public:
		Fixed();
		Fixed(const Fixed &t);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(const Fixed &t);
};

#endif