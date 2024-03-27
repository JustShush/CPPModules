#include "../inc/Fixed.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Fixed::Fixed() {
	std::cout << GREEN << "Default Constructor Called" << RESET << "\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed &t) {
	std::cout << GREEN << "Copy Constructor Called" << RESET << "\n";
	*this = t;
}

Fixed& Fixed::operator=(const Fixed &t) {
	std::cout << GREEN << "Copy Assignment Operator Called" << RESET << "\n";
	this->value = t.value;
	return (*this);
}

// ---------------------- Orthodox Canonical Form -----------------------------

//(i << bit) = (i * 256)
Fixed::Fixed(const int i) {
	std::cout << GREEN << "Int Constructor Called" << RESET << "\n";
	this->setRawBits((i << bit));
}

//roudf(f * (1 << bit) = roundf(f * 256)
Fixed::Fixed(const float f) {
	std::cout << GREEN << "Float Constructor Called" << RESET << "\n";
	this->setRawBits(roundf(f * (1 << bit)));
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor Called" << RESET << "\n";
}

int Fixed::getRawBits(void) const {
	return(this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

//value / (1 << bit) = value / 256
float	Fixed::toFloat(void) const {
	float f;

	f = (float)this->value / (1 << bit);
	return (f);
}

int		Fixed::toInt(void) const {
	int	i;

	i = this->value >> bit;
	return (i);
}

std::ostream& operator<<(std::ostream &ostream, Fixed const &n) {
	ostream << n.toFloat();
	return (ostream);
}