#ifndef BITCOINGEXCHANGE_HPP
# define BITCOINGEXCHANGE_HPP

# include "./header.hpp"

# include <iostream>
# include <map>
# include <sstream>
# include <fstream>
# include <string>

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
};

std::string	dashRM(std::string line);
int	checkDate(int i);

template <typename T>
std::string toString(const T& value) {
	std::stringstream ss;
	ss << value;  // Insert the value (int, float, etc.) into the stream
	return ss.str(); // Return the string
}

#endif