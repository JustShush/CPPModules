#include "../inc/BitcoinExchange.hpp"

std::string	dashRM(std::string line) {
	int	dash = 0;
	for (std::string::iterator it = line.begin(); it < line.end() && *it != ' '; it++) {
		if (*it == '-') {
			dash++;
			line.erase(it);
		}
	}
	if (dash != 2) line.clear();
	return (line);
}

/**
 * Basicly this just checks if there are 8 numbers in the date 12345678
 * @param i The date to check
 * @return the number of digits in a number
 */
int	checkDate(int i) {
	if (i == 0) return 1;

	int count = 0;

	// Make sure to handle negative is
	if (i < 0) i = -i;

	while (i > 0) {
		i /= 10; // Remove the last digit
		++count; // Increment the digit count
	}

	return count;
}
