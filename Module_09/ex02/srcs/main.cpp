#include "PmergeMe.hpp"

void printSequence(const std::string& label, const std::vector<int>& vec) {
	std::cout << label;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << std::endl;
}

void printSequence(const std::string& label, const std::deque<int>& deq) {
	std::cout << label;
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << " " << deq[i];
	std::cout << std::endl;
}

void printPairs(const std::vector<std::pair<int, int> >& pairs) {
	std::cout << CYAN << "🔹 Pairs:" << RESET << std::endl;
	for (size_t i = 0; i < pairs.size(); ++i)
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
	std::cout << std::endl;
}

void printPairs(const std::deque<std::pair<int, int> >& pairs) {
	std::cout << CYAN << "🔹 Pairs (deque):" << RESET << std::endl;
	for (size_t i = 0; i < pairs.size(); ++i)
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
	std::cout << std::endl;
}

void printIndices(const std::vector<size_t>& indices) {
	std::cout << MAGENTA << "🔸 Jacobsthal indices (insertion order):" << RESET << std::endl;
	for (size_t i = 0; i < indices.size(); ++i)
		std::cout << indices[i] << " ";
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

		// Version vector
		std::cout << YELLOW << "\n=== VECTOR MODE ===\n" << RESET;
		printSequence("📥 Before:", pm.getVector());

		std::vector<std::pair<int, int> > pairs = pm.makePairs(pm.getVector());
		printPairs(pairs);

		std::vector<int> maxs = pm.maxInMainChain(pairs);
		printSequence("🔼 Main chain (max):", maxs);

		std::vector<int> mins = pm.minInPending(pairs);
		printSequence("🔽 Pending (min):", mins);

		std::vector<size_t> indices = pm.generateJacobsthalIndices(mins.size());
		printIndices(indices);

		std::vector<int> sortedMain = pm.mergeInsertSortVector(pm.getVector());
		printSequence("✅ Sorted chain (After):", sortedMain);

		pm.measureVectorSort();

		// Version deque
		std::cout << BLUE << "\n=== DEQUE MODE ===\n" << RESET;
		printSequence("📥 Before:", pm.getDeque());

		std::deque<std::pair<int, int> > pairsD = pm.makePairsDeque(pm.getDeque());
		printPairs(pairsD);

		std::deque<int> maxsD = pm.maxInMainChainDeque(pairsD);
		printSequence("🔼 Main chain (max):", maxsD);

		std::deque<int> minsD = pm.minInPendingDeque(pairsD);
		printSequence("🔽 Pending (min):", minsD);

		std::vector<size_t> indicesD = pm.generateJacobsthalIndices(minsD.size());
		printIndices(indicesD);

		std::deque<int> sortedDeque = pm.mergeInsertSortDeque(pm.getDeque());
		printSequence("✅ Sorted chain (After):", sortedDeque);

		pm.measureDequeSort();
	}
	catch (const std::exception& e) {
		std::cerr << RED << "❌ " << e.what() << RESET << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
