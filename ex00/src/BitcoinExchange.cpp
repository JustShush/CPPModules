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

	if (!startExchange(argv)) return false;

	return true;
}

// ****

bool BitcoinExchange::startExchange(std::string argv) {
	std::string line;
	std::ifstream file(argv.c_str());
	if (!file) {
		std::cerr << ON_RED << "ERROR: Could not open the file " << argv << RESET << std::endl;
		return false;
	}
	if (file.peek() == std::ifstream::traits_type::eof()) {
		std::cerr << ON_RED << "ERROR: " << argv << " is an empty file!" << RESET << std::endl;
		return false;
	}
	int i = 0;
	while (getline(file, line)) {
		i++;

		std::string trimmedLine = trim(line);

		if (i == 1) {
			if (trimmedLine.compare("date | value") != 0) {
				std::cerr << ON_RED << "ERROR: Invalid Header!" << RESET <<  std::endl;
				break;
			}
			continue;
		}
		printData(checkLine(trimmedLine));
	}
	return true;
}

std::pair<int, float> BitcoinExchange::checkLine(std::string line) {

	int date = 0;
	float value = 0;
	char end = '\0'; // end of line
	char temp = '\0'; // this is just to check the '|'

	line = dashRM(line);

	std::istringstream iss(line);

	iss >> date >> temp >> value >> end;

	if (checkDate(date) != 8) line.clear();
	else line = dashRM(line);

	if (temp != '|' || (end && end != 'f')) value = 0;
	return (std::make_pair(date, value));
}

bool BitcoinExchange::printData(std::pair<int, float> pair) {

	// make checks and then print to the console
	try {
		if (invalidInput(pair)) throw invalidInputExp();
		if (pair.second < 0) throw negativeNumber();
		if (pair.second > 1000) throw thousandNumber();
	}
	catch (const invalidInputExp &e) {
		std::cerr << ON_RED << "ERROR: " << e.what() << RESET << std::endl;
		printInvalidInput(pair);
		return false;
	}
	catch (const std::exception& e) {
		std::cerr << ON_RED << "ERROR: " << e.what() << RESET << std::endl;
		return false;
	}
	std::cout << printDate(pair.first);
	std::cout << " => " << std::fixed << std::setprecision(sizeof(pair.second) / 2) << pair.second << " = ";
	printValue(pair);
	std::cout << RESET << std::endl;

	return true;
}

void BitcoinExchange::printInvalidInput(std::pair<int, float> pair) {
	std::cout << URED;
	if (pair.first == 0 || pair.second == 0)
		std::cout << "Wrong format";
	else if (checkDate(pair.first) != 8)
		std::cout << "Invalid date!";
	else if (!isLeapYear(pair.first) && pair.first / 100 % 100 == 2 && pair.first % 100 == 29)
		std::cout << "Invalid date! Check Leap Years!";
	else if (pair.first / 100 % 100 > 12 || pair.first / 100 % 100 < 1)
		std::cout << "Invalid Month! Impossible to have a month higher then 12 or lower then 1";
	else if (pair.first % 100 > 31 || pair.first % 100 < 1)
		std::cout << "Invalid Day! Impossible to have days higher then 31 or lower then 1";
	else if (pair.first % 100 > daysInMonth(pair.first))
		std::cout << "Invalid Date!! Impossible day for that month!";
	else {
		std::cout << "Impossible Date!!!!";
	}
	std::cout << RESET << std::endl;
}

void BitcoinExchange::printValue(std::pair<int, float> pair) {

	std::map<int, float>::iterator itDb;
	std::map<int, float>::iterator itPair;

	for (itDb = _db.begin(), itPair = itDb; itDb != _db.end(); itPair = itDb, itDb++) {
		if (pair.first == itDb->first) {
			std::cout << pair.second * itDb->second;
			return ;
		}
		if (pair.first - itDb->first < 0)
			break ;
	}
	std::cout << pair.second * itPair->second;
}

bool BitcoinExchange::invalidInput(std::pair<int, float> pair) {
	if (!pair.first || !pair.second)
		return true;
	if (!isLeapYear(pair.first) && pair.first / 100 % 100 == 2 && pair.first % 100 == 29) // check feb when leapYear
		return true;
	if (checkDate(pair.first) > 8 || pair.first < lDate) // check if valid date like only 8 number for the date
		return true;
	if (pair.first / 100 % 100 > 12 || pair.first / 100 % 100 < 1) // check if valid month
		return true;
	if (pair.first % 100 > 31 || pair.first % 100 < 1) // check for day lower then 1 and higher then 31
		return true;
	if (pair.first % 100 > daysInMonth(pair.first)) // checks if its a valid date, there are only 30 days in september so if its higher then its invalid
		return true;
	return false;
}

/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
const char* BitcoinExchange::negativeNumber::what() const throw() {
	return("Invalid number! It has to be a positive number!");
}

const char* BitcoinExchange::thousandNumber::what() const throw() {
	return("Invalid Number! The number is to large, must be less than 1000!");
}

const char* BitcoinExchange::noDayInMonth::what() const throw() {
	return("Invalid Date! This month doesn\'t have this day.");
}

const char* BitcoinExchange::invalidInputExp::what() const throw() {
	return("Invalid Input!");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */

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
