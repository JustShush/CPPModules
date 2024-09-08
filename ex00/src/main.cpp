#include "../inc/ScalarConverter.hpp"

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << RED << "Invalid input!\n" << ORANGE << "Usage: ./Converter <args>" << RESET << std::endl;
		return 1;
	}

	ScalarConverter::Convert(argv[1]);
	return 0;
}