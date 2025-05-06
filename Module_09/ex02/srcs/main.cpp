#include "PmergeMe.hpp"

void printSequence(const std::string& input, const std::vector<int>& args) {
	std::cout << input;
	for (size_t i = 0; i < args.size(); ++i) {
		std::cout << " " << args[i];
	}
	std::cout << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> >& pairs) {
	std::cout << "Pairs:\n";
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
	}
	std::cout << std::endl;
}


int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << RED << "PmergeMe need args" << RESET << std::endl;
		return EXIT_FAILURE;
	}

	try {
		PmergeMe pm;
		pm.parseArgs(argv, argc);

		std::cout << GREEN << "✅ Arguments validés avec succès !" << RESET << std::endl;
		printSequence("Before:", pm.getVector());

		std::vector<std::pair<int, int> > pairs = pm.makePairs(pm.getVector());
		printPairs(pairs);

		std::vector<int> maxs = pm.maxInMainChain(pairs);
		printSequence("Main chain (max):", maxs);

		std::vector<int> mins = pm.minInPending(pairs);
		printSequence("Pending (min):", mins);

		pm.measureVectorSort();
		pm.measureDequeSort();
		printSequence("After:", pm.getVector());
	}
	catch (const std::exception& e) {
		std::cerr << RED << "❌ " << e.what() << RESET << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
