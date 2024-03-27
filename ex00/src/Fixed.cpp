#include "../inc/Fixed.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Fixed::Fixed()
{
	std::cout << GREEN << "Default Constructor Called" << RESET << "\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << GREEN << "Copy Constructor Called" << RESET << "\n";
	*this = t;
}

Fixed& Fixed::operator=(const Fixed &t)
{
	std::cout << GREEN << "Copy Assignment Operator Called" << RESET << "\n";
	this->value = t.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor Called" << RESET << "\n";
}
// ---------------------- Orthodox Canonical Form -----------------------------

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW << "getRawBits Member Function Called" << RESET << "\n";
	return(this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
