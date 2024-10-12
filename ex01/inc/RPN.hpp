#ifndef RPN_HPP
# define RPN_HPP

# include "./header.hpp"

# include <iostream>
# include <stack>
# include <cstring>
# include <stdlib.h>
# include <sstream>

class RPN {
private:
	std::stack<int> _stack;
	int _numb;
	int _op;
public:
	/* ++ Orthodox Canonical Form ++ */
	RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy_a);
	~RPN();
	/* ++ Orthodox Canonical Form ++ */

	void start(std::string str);
	void isRPN(std::string str);
	void execRPN(std::string str);
	int opRPN(int n, int n1, int op);

};

#endif