#include "../inc/BitcoinExchange.hpp"

std::string	dashRM(std::string line) {
	int	dash = 0;
	for (std::string::iterator it = line.begin(); it < line.end() && *it != ' '; it++) {
		if (*it == '-') {
			dash++;
			line.erase(it);
		}
	}
	//std::cout << dash << std::endl;
	if (dash != 2) line.clear();
	//std::cout << line << std::endl;
	return (line);
}

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

bool isLeapYear(int year) {
	// Check if a year is a leap year
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				return true;  // Divisible by 400: leap year
			else
				return false; // Divisible by 100 but not 400: not a leap year
		} else {
			return true;  // Divisible by 4 but not 100: leap year
		}
	} else {
		return false;  // Not divisible by 4: not a leap year
	}
}

int daysInMonth(int yyyymmdd) {
	// Extract year, month, and day
	int year = yyyymmdd / 10000;
	int month = (yyyymmdd / 100) % 100;
		
	// Check for valid month
	if (month < 1 || month > 12) {
		std::cerr << "Invalid month\n";
		return -1;
	}

	// Array with the days in each month (January = 31, February = 28, etc.)
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Check for leap year in February
	if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	} else {
		return days[month - 1];
	}
}

std::string trim(const std::string &s) {
	size_t start = 0;
	while (start < s.length() && std::isspace(s[start])) {
		start++;
	}

	size_t end = s.length();
	while (end > start && std::isspace(s[end - 1])) {
		end--;
	}

	return s.substr(start, end - start);
}

std::string printDate(const int date) {

	// Extract the year, month, and day from the integer
	int year = date / 10000;			 // Get the year
	int month = (date / 100) % 100;	  // Get the month
	int day = date % 100;				// Get the day

	// Create a string stream to format the date
	std::ostringstream oss;
	oss << std::setw(4) << std::setfill('0') << year << "-" 
		<< std::setw(2) << std::setfill('0') << month << "-" 
		<< std::setw(2) << std::setfill('0') << day;

	return oss.str();
}