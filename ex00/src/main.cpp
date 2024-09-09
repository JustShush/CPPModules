#include "../inc/BitcoinExchange.hpp"

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << RED << "Invalid input!\n" << ORANGE << "Usage: ./btc <args>" << std::endl;
		return -1;
	}

	BitcoinExchange btc;
	btc.loadDB(std::string(argv[1]));

	return 0;
}