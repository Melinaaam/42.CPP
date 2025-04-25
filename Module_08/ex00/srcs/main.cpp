#include "easyfind.hpp"
//acces aleatoire : reclacul a chaque fois memorie necessaire
//acces aleatoire amorti : si tab plein par ex
// std::vector<int>  : tableau dynamique contigu en mémoire.
//                     accès aléatoire auto it O(1), push_back amorti O(1), insertion/effacement milieu O(n).

// std::deque<int>   : “double-ended queue” segmentée.
//                     push_front et push_back O(1), accès aléatoire amorti O(1), insertion milieu O(n).

// std::list<int>    : liste doublement chaînée.
//                     insertion/effacement n’importe où O(1) (avec itérateur), pas d’accès direct par indice (O(n) pour parcourir).

int main()
{
	std::cout << CYAN << " ---- Test with vector ---- " << RESET << std::endl;
	std::vector<int> vect_cont;
	vect_cont.push_back(10);
	vect_cont.push_back(42);
	vect_cont.push_back(1337);

	try {
		std::vector<int>::iterator it = easyfind(vect_cont, 42);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(vect_cont.begin(), it) << "]" << std::endl;

		it = easyfind(vect_cont, 10);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(vect_cont.begin(), it) << "]" << std::endl;

		std::cout << MAGENTA << " ---- Index search failed ---- " << RESET << std::endl;
		it = easyfind(vect_cont, 9);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(vect_cont.begin(), it) << "]" << std::endl;
	}
	catch (const std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl; }

	std::cout << std::endl << CYAN << " ---- Test with deque ---- " << RESET << std::endl;
	std::deque<int> deque_cont;
	deque_cont.push_front(8);
	deque_cont.push_back(1);

	try {
		std::deque<int>::iterator it = easyfind(deque_cont, 8);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(deque_cont.begin(), it) << "]" << std::endl;

		it = easyfind(deque_cont, 1);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(deque_cont.begin(), it) << "]" << std::endl;
	}
	catch (const std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl; }

	try{
		std::cout << MAGENTA << " ---- Index search failed ---- " << RESET << std::endl;
		std::deque<int>::iterator it = easyfind(deque_cont, 42);
		std::cout << "Occurrence of [" << *it << "] found at index ["<< std::distance(deque_cont.begin(), it) << "]" << std::endl;
	}
	catch (const std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl << CYAN << " ---- Test with list ---- " << RESET << std::endl;
	std::list<int> list_cont;
	list_cont.push_front(5);
	list_cont.push_back(4);

	try {
		std::list<int>::iterator it = easyfind(list_cont, 5);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(list_cont.begin(), it) << "]" << std::endl;

		it = easyfind(list_cont, 4);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(list_cont.begin(), it) << "]" << std::endl;
	}
	catch (const std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl; }

	try {
		std::cout << MAGENTA << " ---- Index search failed ---- " << RESET << std::endl;
		std::list<int>::iterator it = easyfind(list_cont, 42);
		std::cout << "Occurrence of [" << *it << "] found at index [" << std::distance(list_cont.begin(), it) << "]" << std::endl;
	}
	catch (const std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl; }

	return 0;
}
