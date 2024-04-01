#include "../inc/Replacer.hpp"

/**
 * @param std::string The file to replace
 * @param std::string The string to find
 * @param std::string The string to replace with
*/
void	replace(std::string filename, const std::string s1, const std::string s2) {

	if (s1.empty() || s2.empty()) {
		std::cout << BRED << "Invalid Input values!\n" << RESET;
		return ;
	}

	std::fstream newFile;
	std::fstream oFile;

	oFile.open(filename.c_str(), std::ios::in);
	if (!oFile.is_open()) {
		std::cout << "Error: Unable to open input file '" << filename << "'.\n";
		return;
	}

	std::string outfile = filename + ".replace";
	newFile.open(outfile.c_str(), std::ios::out);

	if (oFile.is_open()) {
		std::string line;
		while (!oFile.eof()) {
			getline(oFile, line, '\0');
			size_t pos = 0;
			size_t s1len = s1.length();
			size_t s2len = s2.length();
			while ((pos = line.find(s1, pos)) != std::string::npos) {
				line.erase(pos, s1len);
				line.insert(pos, s2);
				pos += s2len;
			}
			newFile << line;
		}
	}
	oFile.close();
	newFile.close();

	std::cout << "Done!\n";
	return ;
}