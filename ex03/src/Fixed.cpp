#include "../inc/Fixed.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Fixed::Fixed() {
	value = 0;
}

Fixed::Fixed(const Fixed &n) {
	*this = n;
}

Fixed& Fixed::operator=(const Fixed &n) {
	setRawBits(n.getRawBits());
	return (*this);
}

Fixed::~Fixed() {}
// ---------------------- Orthodox Canonical Form -----------------------------

Fixed::Fixed(const int i) {
	setRawBits((i << bit));
}

Fixed::Fixed(const float f) {
	setRawBits(roundf(f * (1 << bit)));
}

int Fixed::getRawBits(void) const {
	return(value);
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
}

float	Fixed::toFloat(void) const {
	float f;

	f = (float)getRawBits() / (1 << bit);
	return (f);
}

int		Fixed::toInt(void) const {
	int	i;

	i = getRawBits() >> bit;
	return (i);
}

std::ostream& operator<<(std::ostream &ostream, Fixed const &n) {
	ostream << n.toFloat();
	return (ostream);
}

bool Fixed::operator>(const Fixed &n) const {
	return (getRawBits() > n.getRawBits());
}

bool Fixed::operator<(const Fixed &n) const {
	return (getRawBits() < n.getRawBits());
}

bool Fixed::operator>=(const Fixed &n) const {
	return (getRawBits() >= n.getRawBits());
}

bool Fixed::operator<=(const Fixed &n) const {
	return (getRawBits() <= n.getRawBits());
}

bool Fixed::operator==(const Fixed &n) const {
	return (getRawBits() == n.getRawBits());
}

bool Fixed::operator!=(const Fixed &n) const {
	return (getRawBits() != n.getRawBits());
}

Fixed Fixed::operator+(const Fixed &n) {
	Fixed op;

	op = toFloat() + n.toFloat();
	return (op);
}

Fixed Fixed::operator-(const Fixed &n) {
	Fixed op;

	op = toFloat() - n.toFloat();
	return (op);
}

Fixed Fixed::operator*(const Fixed &n) {
	Fixed op;

	op = toFloat() * n.toFloat();
	return (op);
}

Fixed Fixed::operator/(const Fixed &n) {
	Fixed op;

	if (n.toFloat() == 0)
	{
		std::cout << "Cannot divide by 0! Return Value: ";
		return (1);
	}
	op = toFloat() / n.toFloat();
	return (op);
}

Fixed& Fixed::operator++(void) {
	value++;			// Increment current value
	return (*this);		// Return reference to modified object
}

Fixed& Fixed::operator--(void) {
	value--;			// Decrement current value
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp;			//Create copy of original object
	tmp = *this;
	++(value);	//Incremente value of current object
	return (tmp);		//Return copy of original
}

Fixed Fixed::operator--(int) {
	Fixed tmp;
	tmp = *this;
	--(value);
	return (tmp);
}

Fixed& Fixed::min(Fixed &n1, Fixed &n2) {
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed& Fixed::max(Fixed &n1, Fixed &n2) {
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2) {
	if (n1 < n2)
		return (n1);
	return (n2);
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2) {
	if (n1 > n2)
		return (n1);
	return (n2);
}
