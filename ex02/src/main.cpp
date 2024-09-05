#include "../inc/MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "TOP: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "SIZE: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::itM	it = mstack.begin();
	MutantStack<int>::itM	ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}