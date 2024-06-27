#include "../inc/Converter.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
Converter::Converter() {
	std::cout << GREEN << "Converter Default Constructor Called" << RESET << "\n";
}

Converter::Converter(const Converter &copy) {
	std::cout << GREEN << "Converter Copy Constructor Called" << RESET << "\n";
	*this = copy;
}

Converter& Converter::operator=(const Converter &copy_a) {
	std::cout << GREEN << "Converter Copy Assignment Operator Called" << RESET << "\n";
	(void)copy_a;
	return (*this);
}

Converter::~Converter() {
	std::cout << RED << "Converter Destructor Called" << RESET << "\n";
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void Converter::checkIsPrint(int i) {
	if (i > 126 || i < 33)
		throw NonDisplayableException();
}

void Converter::checkImpossible(double d) {
	if (d > 2147483647 || d < -2147483648)
		throw ImpossibleException();
}

void Converter::handlePseudo(std::string str) {
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		Converter::Pseudo(str);
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		Converter::Pseudo(str);
	else
		throw InvalidTypeException();
	return ;
}

void Converter::Pseudo(std::string str) {
	std::cout << "char: impossible" << "\n";
	std::cout << "int: impossible" << "\n";
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0) {
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str.erase(str.length() - 1) << "\n";
	}
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0) {
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << "\n";
	}
}

void Converter::checkType(std::string str) {
	Converter Conv;
	int	i = 0;
	int	flag = 0;

	if (str[i] == '-')
		i++;
	if (str[i] && str.find_first_not_of("-0123456789.f") == str.npos) {
		while (i < (int)str.length()) {
			if (str[i] == '.' && i + 1 < (int)str.length() && isdigit(str[i + 1]))
				flag++;
			else if (flag == 1 && i == (int)str.length() - 1 && str[i] == 'f') {
				Converter::toFloat(Conv, str);
				return ;
			}
			else if (!isdigit(str[i]) || flag > 1)
				throw InvalidTypeException();
			i++;
		}
		if (flag == 1) {
			Converter::toDouble(Conv, str);
			return ;
		}
		Converter::toInt(Conv, str);
	}
	else if((int)str.length() == 1) {
		Converter::toChar(Conv, str);
	}
	else
		handlePseudo(str);
	return ;
}

// main function to convert the input
void Converter::Convert(std::string str) {
	Converter Conv;
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
const char *Converter::ImpossibleException::what() const throw() {
	return("impossible");
}

const char *Converter::NonDisplayableException::what() const throw() {
	return("Non displayable");
}

const char *Converter::InvalidTypeException::what() const throw() {
	return("Invalid Type");
}
/* /-/-/-/-/-/-/-/-/ Exceptions /-/-/-/-/-/-/-/-/ */

void printIntChar(int i, char c, float f, double d) {
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void printFloatDouble(int i, char c, float f, double d, size_t decimal) {
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
	std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << "\n";
}

void printException(int i, float f, double d, const char *e) {
	std::cout << "char: " << e << "\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void printException2(const char *e) {
	std::cout << "char: " << e << "\n";
	std::cout << "int: " << e << "\n";
	std::cout << "float: " << e << "\n";
	std::cout << "double: " << e << "\n";
}