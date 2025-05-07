#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <stdexcept>
#include <utility>
#include <sstream>
#include <algorithm>
#include <sstream>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parseArgs(char** argv, int argc);

	const std::vector<int>& getVector() const;
	const std::deque<int>& getDeque() const;

	class InvalidArg : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Invalid argument !";
		}
	};

	std::vector<std::pair<int, int> > makePairs(const std::vector<int>& vec) const;
	std::vector<int> maxInMainChain(const std::vector<std::pair<int, int> >& pairs) const;
	std::vector<int> minInPending(const std::vector<std::pair<int, int> >& pairs) const;
	std::vector<int> mergeInsertSortVector(const std::vector<int>& vec);
	void insertWithBinome(std::vector<int>& mainChain, const std::vector<int>& pending, const std::vector<std::pair<int, int> >& pairs);

	std::deque<std::pair<int, int> > makePairsDeque(const std::deque<int>& deq) const;
	std::deque<int> maxInMainChainDeque(const std::deque<std::pair<int, int> >& pairs) const;
	std::deque<int> minInPendingDeque(const std::deque<std::pair<int, int> >& pairs) const;
	std::deque<int> mergeInsertSortDeque(const std::deque<int>& deq);
	void insertWithBinomeDeque(std::deque<int>& mainChain, const std::deque<int>& pending, const std::deque<std::pair<int, int> >& pairs);

	std::vector<size_t> generateJacobsthalIndices(size_t size) const;
	void sortAlgo(void);

private:
	std::vector<int> _vector;
	std::deque<int> _deque;

	bool isNumber(const std::string& str) const;
};

#define BLACK    "\033[0;30m"
#define RED      "\033[0;31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[38;5;220m"
#define BLUE     "\033[0;34m"
#define MAGENTA  "\033[0;35;1m"
#define MAGENTA1 "\033[0;35;2m"
#define MAGENTA2 "\033[0;35;4m"
#define CYAN     "\033[38;5;45m"
#define PINK     "\033[38;5;213m"
#define BOLD     "\033[1m"
#define RESET    "\033[0m"
#define CLIGNOTE "\033[0;35;5m"
#define UNDER_   "\x1b[4m"

#endif
