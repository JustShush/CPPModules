#include "../inc/Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2));
	std::cout << a << "\n";
	std::cout << ++a << "\n";
	std::cout << a << "\n";
	std::cout << a++ << "\n";
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << Fixed::max(a, b) << "\n\n";

	Fixed d(10);
	Fixed e(0);
	Fixed f(10.1f);
	std::cout << "d: "<< d << "\n";
	std::cout << "e: "<< e << "\n";
	std::cout << "f: "<< f << "\n\n";

	std::cout << "d + e  : " << d + e << "\n";
	std::cout << "d - e  : " << d - e << "\n";
	std::cout << "d * e  : " << d * e << "\n";
	std::cout << "d / e  : " << d / e << "\n";

	std::cout << "d > e  : " << (d > e) << "\n";
	std::cout << "d < e  : " << (d < e) << "\n";
	std::cout << "d >= e : " << (d >= e) << "\n";
	std::cout << "d <= e : " << (d <= e) << "\n";
	std::cout << "d != e : " << (d != e) << "\n";
	std::cout << "d == e : " << (d == e) << "\n";
	std::cout << "d == d : " << (d == d) << "\n\n";

	std::cout << "d++ : " << d++ << "\n";
	std::cout << "d   : " << d << "\n";
	std::cout << "d-- : " << d-- << "\n";
	std::cout << "d   : " << d << "\n\n";

	std::cout << "++d : " << ++d << "\n";
	std::cout << "d   : " << d << "\n";
	std::cout << "--d : " << --d << "\n";
	std::cout << "d   : " << d << "\n\n";

	Fixed g(10);
	Fixed h(11);
	std::cout << "min: " << Fixed::min(g, h) << "\n";
	std::cout << "max: " << Fixed::max(g, h) << "\n\n";

	Fixed const i(2.2f);
	Fixed const j(78.9f);
	std::cout << "const min: " << Fixed::min(i, j)  << "\n";
	std::cout << "const max: " << Fixed::max(i, j) << "\n";

	return 0;
}