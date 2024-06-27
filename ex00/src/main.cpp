#include "../inc/Converter.hpp"

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << RED << "Invalid input!\n" << ORANGE << "Usage: ./Converter <args>\n" << RESET;
		return 1;
	}

	Converter::Convert(argv[1]);
	return 0;
}