#include "../inc/RPN.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
RPN::RPN() {
	std::cout << GREEN << "RPN Default Constructor Called" << std::string(RESET) << std::endl;
}

RPN::RPN(const RPN &copy) {
	*this = copy;
	std::cout << GREEN << "RPN Copy Constructor Called" << std::string(RESET) << std::endl;
}

RPN& RPN::operator=(const RPN &copy_a) {
	(void)copy_a;
	std::cout << GREEN << "RPN Copy Assignment Operator Called" << std::string(RESET) << std::endl;
	return (*this);
}

RPN::~RPN() {
	std::cout << RED << "RPN Destructor Called" << std::string(RESET) << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

void RPN::start(std::string str) {

	try {

		std::istringstream iss(str);
		std::string input;

		isRPN(str);
		while (iss >> input)
			execRPN(input);

	} catch (const std::exception& e) {
		std::cerr << std::string(URED) << "ERROR:" << e.what() << std::string(RESET) << '\n';
		return;
	}
	std::cout << _stack.top() << std::endl;
}

void RPN::isRPN(std::string str) {

	_numb = 0;
	_op = 0;
	std::istringstream iss(str);
	std::string input;

	while (iss >> input) {

		if (atoi(input.c_str()) < 0)
			throw std::runtime_error(std::string(URED) + "ERROR: Invalid input! (atoi)" + std::string(RESET));
		if (input.find_first_not_of("0123456789") == std::string::npos)
			_numb++;
		if (input.size() == 1 && strchr("+-*/", input[0]))
			_op++;
	}
	if (_numb - 1 != _op || _op == 0)
		throw std::runtime_error(std::string(URED) + "ERROR: Invalid Expression! (1+1+)" + std::string(RESET));
}

void RPN::execRPN(std::string str) {

	int i = atoi(str.c_str());
	int n, n1;

	if (str.find_first_not_of("0123456789") == std::string::npos)
		_stack.push(i);
	else if (_stack.size() <= 1)
		throw std::runtime_error(std::string(URED) + "ERROR: Stack is EMPTY!" + std::string(RESET));
	else if (str.size() == 1 && strchr("+-*/", str[0])) {
		n1 = _stack.top();
		_stack.pop();
		n = _stack.top();
		_stack.pop();
		_stack.push(opRPN(n, n1, str[0]));
	} else if (isspace(i))
		;
	else
		throw std::runtime_error(std::string(URED) + "ERROR: Invalid Character!" + std::string(RESET));
}

int RPN::opRPN(int n, int n1, int op) {

	switch (op) {
	case '+':
		return n + n1;
		break;
	case '-':
		return n - n1;
		break;
	case '*':
		return n * n1;
		break;
	case '/':
		if (n1 == 0)
			throw std::runtime_error(std::string(URED) + "ERROR: Impossible to divide by 0!!" + std::string(RESET));
		return n / n1;
		break;
	default:
		break;
	}
	throw std::runtime_error(std::string(URED) + "ERROR: Someting When Wrong!!!! (opRPN)" + std::string(RESET));
}
