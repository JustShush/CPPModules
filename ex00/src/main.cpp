#include "../inc/Fixed.hpp"

int main() {

	Fixed a;	//Default
	Fixed b(a); //Copy
	Fixed c;
	c = b;		//Assignment Operator
	std::cout << a.getRawBits() << "\n";
	std::cout << b.getRawBits() << "\n";
	std::cout << c.getRawBits() << "\n";

	std::cout << "\n\n";

	a.setRawBits(2);
	Fixed d;
	d = a;
	Fixed e(a);
	Fixed f(e);

	std::cout << a.getRawBits() << "\n";
	std::cout << d.getRawBits() << "\n";
	std::cout << e.getRawBits() << "\n";
	std::cout << f.getRawBits() << "\n";
	return (0);
}