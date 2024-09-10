#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "./header.hpp"

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <string>
# include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();

	public:
		/* ++ Orthodox Canonical Form ++ */
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter &copy_a);
		/* ++ Orthodox Canonical Form ++ */

		static void Convert(std::string str);
		static void checkType(std::string str);
		static void checkIsPrint(int i);
		static void checkImpossible(double d);
		static void handlePseudo(std::string str);
		static void Pseudo(std::string str);
		static void toInt(ScalarConverter &conv, std::string str);
		static void toChar(ScalarConverter &conv, std::string str);
		static void toDouble(ScalarConverter &conv, std::string str);
		static void toFloat(ScalarConverter &conv, std::string str);

		/* -- Exceptions -- */
		class	NonDisplayableException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class	ImpossibleException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class	InvalidTypeException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		/* -- Exceptions -- */

};

// Adicional functions
void printIntChar(int i, char c, float f, double d);
void printFloatDouble(int i, char c, float f, double d, size_t decimal);
void printException(int i, float f, double d, const char *e);
void printException2(const char *e);

#endif

