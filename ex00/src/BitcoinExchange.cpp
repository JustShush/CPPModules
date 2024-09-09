#include "../inc/BitcoinExchange.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
BitcoinExchange::BitcoinExchange() {
	std::cout << GREEN << "Default Constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
	std::cout << GREEN << "Copy Constructor called" << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy_a) {
	(void)copy_a;
	std::cout << GREEN << "Copy Assignment Operator called" << RESET << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void BitcoinExchange::setFilePath(std::string filepath) {
	_filePath = filepath;
}

std::string BitcoinExchange::getFilePath() {
	return _filePath;
}

bool BitcoinExchange::loadDB(std::string filePath) {
	std::ifstream file(filePath.c_str());
	if (!file) {
		std::cerr << ON_RED << "ERROR: Could not open the file " << filePath << std::endl;
		return false;
	}

	setFilePath(filePath);
	std::cout << getFilePath() << std::endl;

	// start loading the DB

	return true;
}

/* bool loadFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file!" << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		float rate;
		char delimiter;

		// Assuming the file has lines like "2019-07-16,10873.5"
		if (std::getline(ss, date, ',') && ss >> rate) {
			_db[date] = rate;
		} else {
			std::cerr << "Error: Incorrect file format!" << std::endl;
			return false;
		}
	}
	file.close();
	return true;
}

float getRate(const std::string& date) const {
	auto it = _db.find(date);
	if (it != _db.end()) {
		return it->second;
	}
	std::cerr << "Error: Date not found!" << std::endl;
	return -1.0;  // Return an invalid rate if date is not found
}

void display() const {
	for (const auto& pair : _db) {
		std::cout << "Date: " << pair.first << ", Rate: " << pair.second << std::endl;
	}
} */
