#ifndef FIXED_HPP
# define FIXED_HPP

# include "./header.hpp"

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	bit = 8;

	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &t);
		~Fixed();
		Fixed& operator=(const Fixed &t);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &ostream, Fixed const &n);

#endif