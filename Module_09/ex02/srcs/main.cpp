#include "PmergeMe.hpp"







// int main(int argc, char** argv) {
// 	if (argc < 2) {
// 		std::cerr << RED << "PmergeMe need args" << RESET << std::endl;
// 		return 1;
// 	}

// 	try {
// 		PmergeMe pm;
// 		pm.parseArgs(argv, argc);

// 		std::cout << GREEN << "Arguments validés avec succès !" << RESET << std::endl;

// 		std::cout << YELLOW << "\n=== VECTOR MODE ===\n" << RESET;
// 		printSequence("Before:", pm.getVector());

// 		std::vector<std::pair<int, int> > pairs = pm.makePairs(pm.getVector());
// 		printPairs(pairs);

// 		std::vector<int> maxs = pm.maxInMainChain(pairs);
// 		printSequence("Main chain (max):", maxs);

// 		std::vector<int> mins = pm.minInPending(pairs);
// 		printSequence("Pending (min):", mins);

// 		std::vector<size_t> indices = pm.generateJacobsthalIndices(mins.size());
// 		printIndices(indices);

// 		std::vector<int> sortedMain = pm.mergeInsertSortVector(pm.getVector());
// 		printSequence("✅ Sorted chain (After):", sortedMain);

// 		pm.measureVectorSort();

// 		std::cout << BLUE << "\n=== DEQUE MODE ===\n" << RESET;
// 		printSequence("Before:", pm.getDeque());

// 		std::deque<std::pair<int, int> > pairsD = pm.makePairsDeque(pm.getDeque());
// 		printPairs(pairsD);

// 		std::deque<int> maxsD = pm.maxInMainChainDeque(pairsD);
// 		printSequence("Main chain (max):", maxsD);

// 		std::deque<int> minsD = pm.minInPendingDeque(pairsD);
// 		printSequence("Pending (min):", minsD);

// 		std::vector<size_t> indicesD = pm.generateJacobsthalIndices(minsD.size());
// 		printIndices(indicesD);

// 		std::deque<int> sortedDeque = pm.mergeInsertSortDeque(pm.getDeque());
// 		printSequence("Sorted chain (After):", sortedDeque);

// 		pm.measureDequeSort();
// 	}
// 	catch (const std::exception& e) {
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 		return 1;
// 	}
// 	return 0;
// }

int main(int ac, char** av)
{
	if (ac < 2) {
		std::cerr << "Error: no argument given. " << std::endl;
		return (1);
	}
	try	{
		PmergeMe pm;
		pm.parseArgs(av, ac);
		pm.sortAlgo();

	}
	catch(const std::exception& e) {
		std::cerr << RED << "Error: " << RESET << BOLD << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}