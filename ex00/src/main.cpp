#include "../inc/whatever.hpp"

int	main( void )
{
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::string	str1 = "Equal";
	std::string	str2 = "Equal";

	std::cout << "min( str1, str2 ) = " << ::min( str1, str2 ) << std::endl;
	std::cout << "max( str1, str2 ) = " << ::max( str1, str2 ) << std::endl;

	return 0;

}

/* int main(void) {

	std::string a = "a";
	std::string b = "b";

	std::cout << RED << "Before SWAP" << RESET << std::endl << "a: " << a << " | b: " << b << std::endl;
	swap(a, b);
	std::cout << GREEN << "After SWAP" << RESET << std::endl << "a: " << a << " | b: " << b << std::endl;
	a = "a";
	b = "b";
	std::cout << "min(" << a << ", " << b << ")= " << myMin(a, b) << std::endl;
	std::cout << "max(" << a << ", " << b << ")= " << myMax(a, b) << std::endl;

	int num1 = 10;
	int num2 = 11;

	std::cout << RED << "Before SWAP" << RESET << std::endl << "num1: " << num1 << " | num2: " << num2 << std::endl;
	swap(num1, num2);
	std::cout << RED << "After SWAP" << RESET << std::endl << "num1: " << num1 << " | num2: " << num2 << std::endl;
	num1 = 10;
	num2 = 11;
	std::cout << "min(" << num1 << ", " << num2 << ")= " << myMin(num1, num2) << std::endl;
	std::cout << "max(" << num1 << ", " << num2 << ")= " << myMax(num1, num2) << std::endl;

	num1 = 42;
	num2 = 42;
	std::cout << ORANGE << "They are equal now!" << std::endl;
	std::cout << "min(" << num1 << ", " << num2 << ")= " << myMin(num1, num2) << std::endl;
	std::cout << "max(" << num1 << ", " << num2 << ")= " << myMax(num1, num2) << std::endl;

	return 0;
} */