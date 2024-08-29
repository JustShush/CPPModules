#include "../inc/iter.hpp"

int	main(void) {

	std::cout << "INTs" << std::endl;
	int numbers[5] = { 0, 1, 2, 3, 4 };

	::iter(numbers, 5, myPrint<int>);

	std::cout << "STRINGs" << std::endl;
	std::string strings[5] = { "a", "b", "c", "d", "e" };

	::iter(strings, 5, myPrint<std::string>);

	return 0;
}