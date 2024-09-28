#ifndef BITCOINGEXCHANGE_HPP
# define BITCOINGEXCHANGE_HPP

# include "./header.hpp"

# include <iostream>
# include <map>
# include <sstream>
# include <fstream>
# include <string>
# include <iomanip>

class BitcoinExchange {
private:
	std::map<int, float> _db;
	int lDate;
	std::string _filePath;
public:
	/* ++ Orthodox Canonical Form ++ */
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy_a);
	~BitcoinExchange();
	/* ++ Orthodox Canonical Form ++ */

	// Getters / Setters
	void setLDate(int date);
	void setFilePath(std::string filepath);
	std::string getFilePath();

	// Addicional Functions
	bool loadDB(std::string argv);
	bool startExchange(std::string argv);

	std::pair<int, float> checkLine(std::string line);
	bool printData(std::pair<int, float> pair);
	void printInvalidInput(std::pair<int, float> pair);
	void printValue(std::pair<int, float> pair);
	bool invalidInput(std::pair<int, float> pair);

	/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
	class negativeNumber : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class thousandNumber : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class noDayInMonth : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class invalidInputExp : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */

};

std::string	dashRM(std::string line);
int	checkDate(int i);
bool isLeapYear(int year);
int daysInMonth(int yyyymmdd);
std::string trim(const std::string &s);
std::string printDate(const int date);

template <typename T>
std::string toString(const T& value) {
	std::stringstream ss;
	ss << value;  // Insert the value (int, float, etc.) into the stream
	return ss.str(); // Return the string
}

#endif