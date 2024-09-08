#include "../inc/ScalarConverter.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
ScalarConverter::ScalarConverter() {
	std::cout << GREEN << "Converter Default Constructor Called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
	std::cout << GREEN << "Converter Copy Constructor Called" << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy_a) {
	(void)copy_a;
	std::cout << GREEN << "Converter Copy Assignment Operator Called" << RESET << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << RED << "Converter Destructor Called" << RESET << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void ScalarConverter::checkIsPrint(int i) {
	if (i > 126 || i < 33)
		throw NonDisplayableException();
}

void ScalarConverter::checkImpossible(double d) {
	if (d > INT_MAX || d < INT_MIN)
		throw ImpossibleException();
}

void ScalarConverter::handlePseudo(std::string str) {
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		Pseudo(str);
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		Pseudo(str);
	else
		throw InvalidTypeException();
	return ;
}

void ScalarConverter::Pseudo(std::string str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0) {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.erase(str.length() - 1) << std::endl;
	}
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0) {
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << std::endl;
	}
}

void ScalarConverter::checkType(std::string str) {
	ScalarConverter Conv;
	int	i = 0;
	int	flag = 0;

	if (str[i] == '-')
		i++;
	if (str[i] && str.find_first_not_of("-0123456789.f") == str.npos) {
		while (i < (int)str.length()) {
			if (str[i] == '.' && i + 1 < (int)str.length() && isdigit(str[i + 1]))
				flag++;
			else if (flag == 1 && i == (int)str.length() - 1 && str[i] == 'f') {
				toFloat(Conv, str);
				return ;
			}
			else if (!isdigit(str[i]) || flag > 1)
				throw InvalidTypeException();
			i++;
		}
		if (flag == 1) {
			toDouble(Conv, str);
			return ;
		}
		toInt(Conv, str);
	}
	else if((int)str.length() == 1) {
		toChar(Conv, str);
	}
	else
		handlePseudo(str);
	return ;
}

// main function to convert the input
void ScalarConverter::Convert(std::string str) {
	std::string type;

	try {
		checkType(str);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
		return ;
	}
}

/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */
const char *ScalarConverter::ImpossibleException::what() const throw() {
	return("impossible");
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
	return("Non displayable");
}

const char *ScalarConverter::InvalidTypeException::what() const throw() {
	return("Invalid Type");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */

void printIntChar(int i, char c, float f, double d) {
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void printFloatDouble(int i, char c, float f, double d, size_t decimal) {
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
	std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << std::endl;
}

void printException(int i, float f, double d, const char *e) {
	std::cout << "char: " << e << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void printException2(const char *e) {
	std::cout << "char: " << e << std::endl;
	std::cout << "int: " << e << std::endl;
	std::cout << "float: " << e << std::endl;
	std::cout << "double: " << e << std::endl;
}