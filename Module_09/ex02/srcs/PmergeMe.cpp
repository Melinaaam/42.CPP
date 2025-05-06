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

void PmergeMe::sort() {}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) {
	(void)deq;
}

void PmergeMe::parseArgs(char** argv, int argc) {
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (!isNumber(arg))
			throw PmergeMe::InvalidArg();
		int number = std::stoi(arg);
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

void PmergeMe::measureVectorSort() {
	std::vector<int> vecCopy = _vector;
	clock_t start = clock();
	mergeInsertSortVector(vecCopy);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << vecCopy.size() << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::measureDequeSort() {
	std::deque<int> deqCopy = _deque;
	clock_t start = clock();
	mergeInsertSortDeque(deqCopy);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << deqCopy.size() << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
	std::vector<std::pair<int, int> > pairs = makePairs(vec);
	std::vector<int> mainChain = maxInMainChain(pairs);
	std::sort(mainChain.begin(), mainChain.end());
	std::vector<int> pendingChain = minInPending(pairs);
	(void)vec;
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
