#include"PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& copy) {
	_vector = copy._vector;
	_deque = copy._deque;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if(this != &other){
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

const std::vector<int>& PmergeMe::getVector() const {return _vector;}
const std::deque<int>& PmergeMe::getDeque() const {return _deque;}

/***********************PARSING***********************/
void PmergeMe::parseArgs(char** argv, int argc) {
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (!isNumber(arg))
			throw PmergeMe::InvalidArg();
		std::istringstream iss(arg);
		int number;
		iss >> number;
		if (iss.fail() || !iss.eof())
			throw PmergeMe::InvalidArg();
		if (number < 0)
			throw PmergeMe::InvalidArg();
		_vector.push_back(number);
		_deque.push_back(number);
	}
}

bool PmergeMe::isNumber(const std::string& str) const {
	if (str.empty())
		return false;
	for(size_t i = 0; i < str.length(); i++){
		if(!isdigit(str[i]))
			return false;
	}
	return true;
}


/***********************FORDJ ALGO VECTOR***********************/
std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& vec) {
	std::vector<std::pair<int, int> > pairs = makePairs(vec);
	std::vector<int> mainChain = maxInMainChain(pairs);
	std::sort(mainChain.begin(), mainChain.end());
	std::vector<int> pendingChain = minInPending(pairs);

	insertWithBinome(mainChain, pendingChain, pairs);
	if (vec.size() % 2 != 0) {
		int last = vec.back();

		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(it, last);
	}
	return mainChain;
}


std::vector<std::pair<int, int> > PmergeMe::makePairs(const std::vector<int>& vec) const {
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	return pairs;
}

std::vector<int> PmergeMe::maxInMainChain(const std::vector<std::pair<int, int> >& pairs) const {
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
		int max;
		if (pairs[i].first > pairs[i].second)
			max = pairs[i].first;
		else
			max = pairs[i].second;
		mainChain.push_back(max);
	}
	return mainChain;
}

std::vector<int> PmergeMe::minInPending(const std::vector<std::pair<int, int> >& pairs) const {
	std::vector<int> pendingChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
		int min;
		if (pairs[i].first > pairs[i].second)
			min = pairs[i].second;
		else
			min = pairs[i].first;
		pendingChain.push_back(min);
	}
	return pendingChain;
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t size) const {
	std::vector<size_t> indices;
	if (size == 0)
		return indices;

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (true) {
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		if (next >= size)
			break;
		jacob.push_back(next);
	}
	std::vector<bool> added(size, false);
	for (size_t i = 1; i < jacob.size(); ++i) {
		if (jacob[i] < size && !added[jacob[i]]) {
			indices.push_back(jacob[i]);
			added[jacob[i]] = true;
		}
	}
	for (size_t i = 0; i < size; ++i) {
		if (!added[i])
			indices.push_back(i);
	}
	return indices;
}

void PmergeMe::insertWithBinome(std::vector<int>& mainChain, const std::vector<int>& pending, const std::vector<std::pair<int, int> >& pairs) {
	std::vector<std::pair<int, int> > binomeList;

	for (size_t i = 0; i < pairs.size(); ++i) {
		int a = pairs[i].first;
		int b = pairs[i].second;
		if (a > b)
			binomeList.push_back(std::make_pair(b, a));
		else
			binomeList.push_back(std::make_pair(a, b));
	}
	std::vector<size_t> order = generateJacobsthalIndices(pending.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int value = pending[order[i]];
		int binome = -1;
		for (size_t j = 0; j < binomeList.size(); ++j) {
			if (binomeList[j].first == value) {
				binome = binomeList[j].second;
				break;
			}
		}
		std::vector<int>::iterator binomeIt = std::find(mainChain.begin(), mainChain.end(), binome);
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), binomeIt, value);
		mainChain.insert(pos, value);
	}
}

/***********************FORDJ ALGO DEQUE***********************/

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& deq) {
	std::deque<std::pair<int, int> > pairs = makePairsDeque(deq);
	std::deque<int> mainChain = maxInMainChainDeque(pairs);
	std::sort(mainChain.begin(), mainChain.end());
	std::deque<int> pendingChain = minInPendingDeque(pairs);

	insertWithBinomeDeque(mainChain, pendingChain, pairs);
	if (deq.size() % 2 != 0) {
		int last = deq.back();
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(it, last);
	}
	return mainChain;
}

std::deque<std::pair<int, int> > PmergeMe::makePairsDeque(const std::deque<int>& deq) const {
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
	}
	return pairs;
}

std::deque<int> PmergeMe::maxInMainChainDeque(const std::deque<std::pair<int, int> >& pairs) const {
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
		int max = (pairs[i].first > pairs[i].second) ? pairs[i].first : pairs[i].second;
		mainChain.push_back(max);
	}
	return mainChain;
}

std::deque<int> PmergeMe::minInPendingDeque(const std::deque<std::pair<int, int> >& pairs) const {
	std::deque<int> pendingChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
		int min = (pairs[i].first < pairs[i].second) ? pairs[i].first : pairs[i].second;
		pendingChain.push_back(min);
	}
	return pendingChain;
}

void PmergeMe::insertWithBinomeDeque(std::deque<int>& mainChain, const std::deque<int>& pending, const std::deque<std::pair<int, int> >& pairs) {
	std::deque<std::pair<int, int> > binomeList;

	for (size_t i = 0; i < pairs.size(); ++i) {
		int a = pairs[i].first;
		int b = pairs[i].second;
		if (a > b)
			binomeList.push_back(std::make_pair(b, a));
		else
			binomeList.push_back(std::make_pair(a, b));
	}
	std::vector<size_t> order = generateJacobsthalIndices(pending.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int value = pending[order[i]];
		int binome = -1;

		for (size_t j = 0; j < binomeList.size(); ++j) {
			if (binomeList[j].first == value) {
				binome = binomeList[j].second;
				break;
			}
		}
		std::deque<int>::iterator binomeIt = std::find(mainChain.begin(), mainChain.end(), binome);
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), binomeIt, value);
		mainChain.insert(pos, value);
	}
}

static void printSequenceVector(const std::string& label, const std::vector<int>& vec) {
	std::cout << label << CYAN;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << RESET << std::endl;
}

static void printSequenceDeque(const std::string& label, const std::deque<int>& deq) {
	std::cout << label << MAGENTA ;
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << " " << deq[i];
	std::cout << RESET << std::endl;
}

void PmergeMe::sortAlgo()
{
	std::cout << BOLD << "Before " << RESET;
	printSequenceVector("vector", _vector);
	std::cout << BOLD << "Before " << RESET;
	printSequenceDeque("deque", _deque);

	clock_t startV = clock();
	_vector = mergeInsertSortVector(_vector);
	clock_t endV = clock();
	double durationV = static_cast<double>(endV - startV) / CLOCKS_PER_SEC * 1000000;

	clock_t startD = clock();
	_deque = mergeInsertSortDeque(_deque);
	clock_t endD = clock();
	double durationD = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000000;

	std::cout << BOLD << "After " << RESET;
	printSequenceVector("vector", _vector);
	std::cout << BOLD << "After " << RESET;
	printSequenceDeque("deque", _deque);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::" << "vector" << ": ";
	if (durationV > durationD)
		std::cout << RED << durationV;
	else
		std::cout << GREEN << durationV;

	std::cout << RESET << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::" << "deque" << ": ";
	if (durationD > durationV)
		std::cout << RED << durationD;
	else
		std::cout << GREEN << durationD;
	std::cout << RESET << " us" << std::endl;
}