#include "../inc/MutantStack.hpp"
#include <list>

int main() {
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "TOP: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "SIZE: "<< mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::itM	it = mstack.begin();
		MutantStack<int>::itM	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		// The 2 outputs are not EXACLY the same cuz stack is a Last-In-First-Out data structure
		std::cout << ON_GREEN << "Now just the same thing but with a list (should have the same behaviour)" << RESET << std::endl;

		std::list<int> list;

		list.push_back(5);
		list.push_back(17);

		std::cout << "TOP: " << list.front() << std::endl;

		list.pop_back();

		std::cout << "SIZE: " << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator itEnd = list.end();

		++it;
		--it;

		while (it != itEnd) {
			std::cout << *it << std::endl;
			++it;
		}

	}
	return 0;
}
