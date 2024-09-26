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

void BitcoinExchange::setLDate(int date) {
	lDate = date;
}

void BitcoinExchange::setFilePath(std::string filepath) {
	_filePath = filepath;
}

std::string BitcoinExchange::getFilePath() {
	return _filePath;
}

bool BitcoinExchange::loadDB(std::string argv) {
	std::string line;
	std::string filePath = "../data.csv";
	std::ifstream file(filePath.c_str());
	if (!file) {
		std::cerr << ON_RED << "ERROR: Could not open the file " << filePath << std::endl;
		return false;
	}

	setFilePath(argv);
	std::cout << getFilePath() << std::endl;

	// start loading the DB

	// set the lowest date to 0, cuz theres is not yet
	setLDate(0);

	while (!file.eof()) {
		getline(file, line);
		std::string cleanLine = dashRM(line);

		int date = 0;
		char temp = ','; // this is just to save the ','
		float value = 0;

		std::istringstream iss(cleanLine);
		if (iss >> date >> temp >> value) {
			if (checkDate(date) != 8) return false;
			_db.insert(std::make_pair(date, value));
		}
	}

	for (std::map<int, float>::iterator it = _db.begin(); it != _db.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	if (!startExchange(argv)) return false;

	return true;
}

std::pair<int, float> BitcoinExchange::checkLine(std::string line) {
	int date = 0;
	float value = 0;
	char end = '\0'; // end of line
	char temp; // this is just to check the '|'

	if (checkDate(date) != 0) line.clear();
	else line = dashRM(line);

	std::istringstream iss(line);

	iss >> date >> temp >> value >> end;
	if (temp != '|' || (end && end != 'f')) value = 0;
	return (std::make_pair(date, value));

}

bool BitcoinExchange::printData(std::pair<int, float> pair) {

	(void)pair;
	// make checks and then print to the console

	return true;
}

bool BitcoinExchange::startExchange(std::string argv) {

	std::string line;
	std::ifstream file(argv.c_str());
	if (!file) {
		std::cerr << ON_RED << "ERROR: Could not open the file " << argv << RESET << std::endl;
		return false;
	}
	if (file.eof()) {
		std::cerr << ON_RED << "ERROR: " << argv << " is an empty file!" << RESET << std::endl;
		return false;
	}
	int i = 0;
	while (getline(file, line)) {
		if (line.compare("date | value") == 0) continue;
		if (i == 0) {
			std::cerr << ON_RED << "ERROR: Invalid Header!" << RESET <<  std::endl;
			return false;
		}
		printData(checkLine(line));
	}

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
