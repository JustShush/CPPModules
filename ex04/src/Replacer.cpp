#include "../inc/Replacer.hpp"

/**
 * @param std::string The file to replace
 * @param std::string The string to find
 * @param std::string The string to replace with
*/
std::string replace(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inFile(filename); // Open the input file
	if (!inFile) {
		std::cerr << "Unable to open input file: " << filename << std::endl;
		return;
	}

	std::string content, line;
	while (std::getline(inFile, line)) {
		content += line + "\n"; // Read the file line by line
	}
	inFile.close(); // Close the input file

	size_t startPos = 0; // Start position of search
	while ((startPos = content.find(toReplace, startPos)) != std::string::npos) {
		content.replace(startPos, toReplace.length(), replaceWith); // Replace the string
		startPos += replaceWith.length(); // Move position after replacement
	}

	std::ofstream outFile(filename); // Open the output file
	if (!outFile) {
		std::cerr << "Unable to open output file: " << filename << std::endl;
		return;
	}
	outFile << content; // Write modified content to output file
	outFile.close(); // Close the output file
}