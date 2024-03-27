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
		Fixed(const Fixed &n);
		Fixed(const int i);
		Fixed(const float f);

		Fixed& operator=(const Fixed &n);

		~Fixed();

		bool operator>(const Fixed &n) const;
		bool operator<(const Fixed &n) const;
		bool operator>=(const Fixed &n) const;
		bool operator<=(const Fixed &n) const;
		bool operator==(const Fixed &n) const;
		bool operator!=(const Fixed &n) const;
		Fixed operator+(const Fixed &n);
		Fixed operator-(const Fixed &n);
		Fixed operator*(const Fixed &n);
		Fixed operator/(const Fixed &n);
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed& min(Fixed &n1, Fixed &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		static const Fixed& min(const Fixed &n1, const Fixed &n2);
		static const Fixed& max(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<<(std::ostream &ostream, Fixed const &n);

#endif