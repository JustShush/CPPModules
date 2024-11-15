#include "../inc/PmergeMe.hpp"

/* ++++++++++ Orthodox Canonical Form ++++++++++ */
PmergeMe::PmergeMe() {
	std::cout << GREEN << "PmergeMe Default Constructor Called" << std::string(RESET) << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
	std::cout << GREEN << "PmergeMe Copy Constructor Called" << std::string(RESET) << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy_a) {
	(void)copy_a;
	std::cout << GREEN << "PmergeMe Copy Assignment Operator Called" << std::string(RESET) << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe() {
	std::cout << RED << "PmergeMe Destructor Called" << std::string(RESET) << std::endl;
}
/* ++++++++++ Orthodox Canonical Form ++++++++++ */

std::pair<int, int>	PmergeMe::makePair(int n1, int n2) {

	std::pair<int, int>	p;

	if (n1 <= n2) {
		p.first = n1;
		p.second = n2;
	} else {
		p.first = n2;
		p.second = n1;
	}
	return (p);
}

int JacobsthalSequence(int n) {

	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	return JacobsthalSequence(n - 1) + (2 * JacobsthalSequence(n - 2));
}

void PmergeMe::populateJBSequence() {

	JBSequence.reserve(15);
	for (int i = 0; i < 15; i++) {
		int j = JacobsthalSequence(i + 1) - JacobsthalSequence(i);
		if (j >= 0)
			JBSequence.push_back(j);
	}
}

// sorts the pairs in the vector vec by their first element (the largest value in the pair)
void PmergeMe::firstSortVector(int start) {

	int	buf = INT_MAX;
	int	maxPos = 0;
	std::pair<int, int> tempPair;

	for (int i = start; i < numb / 2; i++) {
		if (vec[i].first < buf) {
			tempPair = vec[i];
			buf = vec[i].first;
			maxPos = i;
		}
	}
	vec.erase(vec.begin() + maxPos);
	vec.insert(vec.begin() + start, tempPair);
}

void PmergeMe::pairToVetor(int argc, char *argv[]) {

	int	n1 = 0;
	numb = argc - 1;
	for (int i = 1; i <= numb; i++) {

		n1 = atoi(argv[i++]);
		if (i <= numb)
			vec.push_back(makePair(n1, atoi(argv[i])));
		else
			vec.push_back(makePair(-1, n1));
	}
	for (int i = 0; i < numb / 2; i++)
		firstSortVector(i);
}

void PmergeMe::pairToList(int argc, char *argv[]) {
	int	i;
	int	n1 = 0;

	numb = argc - 1;
	for (i = 1; i <= numb; i++)
	{
		n1 = atoi(argv[i++]);
		if (i <= numb)
			list.push_back(makePair(n1, atoi(argv[i])));
		else
			list.push_back(makePair(-1, n1));
	}
	list.sort();
}

/**
 * binary search algorithm to find the correct index where a value b should be inserted
 * into a sorted vector vec.
 * 
 * The goal of this function is to perform an efficient search to determine where
 * b should be placed in vec such that vec remains sorted after the insertion.
 */
int	binaryInsert(std::vector<int> &v, int b) {

	int	low = 0;
	int	high = v.size();

	while (low <= high) {
		int mid = (low + high) / 2;
		if (b <= v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (low);
}

std::list<int>::iterator	PmergeMe::binarySearchList(std::list<int> &list, int b) {

	std::list<int>::iterator	low = list.begin();
	std::list<int>::iterator	high = list.end();
	--high;
	while (low != high) {
		std::list<int>::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (b < *mid)
			high = mid;
		else
			low = ++mid;
	}
	return low;
}

void	PmergeMe::insertFirst(std::vector<std::pair<int, int> > &vec) {

	std::vector<std::pair<int, int> >::iterator	it;
	for (it = vec.begin(); it < vec.end(); it++) {
		if (it->first == -1)
			continue ;
		sortedVec.push_back(it->first);
	}
}

void PmergeMe::pushFirst(std::list<std::pair<int, int> > &list) {

	std::list<std::pair<int, int> >::iterator	a;
	for (a = list.begin(); a != list.end(); a++) {
		if (a->first == -1)
			continue ;
		sortedList.push_back(a->first);
	}
}

void printVector(const std::vector<int>& vec) {
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::FordJohnsonVec() {

	insertFirst(vec);
	int	x = 0;
	int	y = JBSequence[2];
	int	w = 0;
	if ((int)vec.size() == 1)
		y = 1;
	for (int i = 2; i < (int)JBSequence.size() && y <= (int)vec.size(); i++) {
		for (x = y - 1; x >= w; x--) {
			if (vec[x].second > sortedVec[sortedVec.size() - 1])
				sortedVec.push_back(vec[x].second);
			else
				sortedVec.insert(sortedVec.begin() + binaryInsert(sortedVec, vec[x].second), vec[x].second);
		}
		w = y;
		y += JBSequence[i];
		if (y + JBSequence[i] > vec.size())
			y = vec.size();
	}
}

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

void	PmergeMe::FordJohnsonList() {

	pushFirst(list);
	int	x = 0;
	int	y = JBSequence[2];
	int	w = 0;
	if ((int)vec.size() == 1)
		y = 1;
	for (int i = 3; i < (int)JBSequence.size() && y <= (int)list.size(); i++)
	{
		for (x = y - 1; x >= w;)
		{
			std::list<int>::iterator last = sortedList.end();
			--last;
			std::list<std::pair<int, int> >::iterator it = list.begin();
			std::advance(it, x);
			if (it->second < *last)
				sortedList.insert(binarySearchList(sortedList, it->second), it->second);
			else
				sortedList.push_back(it->second);
			x--;
		}
		w = y;
		y += JBSequence[i];
		if (y >= (int)list.size())
			y = list.size();
	}
}

void	PmergeMe::output(int argc, char *argv[], std::clock_t vEnd, std::clock_t lEnd) {

	std::cout << "Before:	";
	for (int i = 1; i < argc; i++) {

		std::cout << atoi(argv[i]);
		if (i + 1 != argc)
			std::cout << " ";
	}
	std::cout << "\n";
	std::cout << "Vec After:	" << CYAN;
	printContainer(sortedVec);

	std::cout << "List After:	" << ORANGE;
	printContainer(sortedList);

	std::cout << "Time to process " << argc - 1 << " elements with [" << CYAN;
	printFunctionName(sortedVec);
	std::cout << RESET << "] : " << static_cast<double>(vEnd)/CLOCKS_PER_SEC * 1000 << " μs microsec\n";

	std::cout << "Time to process " << argc - 1 << " elements with [" << ORANGE;
	printFunctionName(sortedList);
	std::cout << RESET << "] : " << static_cast<double>(lEnd)/CLOCKS_PER_SEC * 1000 << " μs microsec \n";
}

void PmergeMe::start(int argc, char *argv[]) {

	std::clock_t vecStart;
	std::clock_t vecEnd;
	std::clock_t listStart;
	std::clock_t listEnd;

	populateJBSequence();

	vecStart = std::clock();
	pairToVetor(argc, argv);
	FordJohnsonVec();
	vecEnd = std::clock() - vecStart;

	listStart = std::clock();
	pairToList(argc, argv);
	FordJohnsonList();
	listEnd = std::clock() - listStart;

	output(argc, argv, vecEnd, listEnd);
}