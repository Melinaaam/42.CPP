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

/***********************TIMING***********************/
void PmergeMe::measureVectorSort() {
	std::vector<int> vecCopy = _vector;
	clock_t start = clock();
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << vecCopy.size() << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::measureDequeSort() {
	std::deque<int> deqCopy = _deque;
	clock_t start = clock();
	std::deque<int> sorted = mergeInsertSortDeque(deqCopy);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << deqCopy.size() << " elements with std::deque : " << duration << " us" << std::endl;
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
		std::cout << YELLOW << "🔸 Inserting unpaired last element: " << last << RESET << std::endl;
		std::cout << "    before insert: ";
		for (size_t k = 0; k < mainChain.size(); ++k)
			std::cout << mainChain[k] << " ";
		std::cout << std::endl;

		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(it, last);

		std::cout << "    after  insert: ";
		for (size_t k = 0; k < mainChain.size(); ++k)
			std::cout << mainChain[k] << " ";
		std::cout << "\n" << std::endl;

	}

	std::cout << GREEN << "✅ Final sorted mainChain: ";
	for (size_t i = 0; i < mainChain.size(); ++i)
		std::cout << mainChain[i] << " ";
	std::cout << RESET << std::endl;


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

	// Construction du tableau (min, max)
	for (size_t i = 0; i < pairs.size(); ++i) {
		int a = pairs[i].first;
		int b = pairs[i].second;
		if (a > b)
			binomeList.push_back(std::make_pair(b, a));
		else
			binomeList.push_back(std::make_pair(a, b));
	}

	// Ordre d'insertion selon Jacobsthal
	std::vector<size_t> order = generateJacobsthalIndices(pending.size());

	for (size_t i = 0; i < order.size(); ++i) {
		int value = pending[order[i]];
		int binome = -1;

		// Trouver le binôme correspondant dans binomeList
		for (size_t j = 0; j < binomeList.size(); ++j) {
			if (binomeList[j].first == value) {
				binome = binomeList[j].second;
				break;
			}
		}

		// Chercher où insérer avant le binôme
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
