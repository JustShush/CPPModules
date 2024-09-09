#ifndef BITCOINGEXCHANGE_HPP
# define BITCOINGEXCHANGE_HPP

# include "./header.hpp"

# include <iostream>
# include <map>
# include <fstream>
# include <string>

class BitcoinExchange {
private:
	std::map<std::string, float> _db;
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
	void setFilePath(std::string filepath);
	std::string getFilePath();

	// Addicional Functions
	bool loadDB(std::string filePath);
};

#endif