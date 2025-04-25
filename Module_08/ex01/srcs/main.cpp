#include "Span.hpp"


void printSpan(const Span& s) {
	std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int main()
{
	std::cout << CYAN << " ---- subject test ---- " << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << CYAN << " ---- My tests ---- " << RESET << std::endl;

	Span mySpan(4);
	try {
		mySpan.addNumber(1);
		mySpan.addNumber(2);
		mySpan.addNumber(3);
		mySpan.addNumber(4);
		std::cout << YELLOW << " print mySpan " << RESET << std::endl;
		printSpan(mySpan);
		std::cout << "The shortestSpan : [" << mySpan.shortestSpan() << "]" << std::endl;
		std::cout << "The longestSpan : [" << mySpan.longestSpan() << "]" << std::endl;

		std::cout << std::endl << MAGENTA1 << "Trying to add in full span " << RESET << std::endl;
		mySpan.addNumber(5);
	}
	catch (const std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl; }

	std::cout << std::endl << CYAN << " Tests with range of iterators " << RESET << std::endl;
	std::vector<int> vector1;
	for (int i = 0; i < 20; ++i)
		vector1.push_back(i * 3);

	Span anotherSpan(20);
	anotherSpan.addNumber(vector1.begin(), vector1.end());

	std::cout << "Contenu après addNumber(vector): ";
	printSpan(anotherSpan);

	std::cout << "The shortestSpan : [" << anotherSpan.shortestSpan() << "]" << std::endl;
	std::cout << "The longestSpan : [" << anotherSpan.longestSpan() << "]" << std::endl << std::endl;

	std::cout << std::endl << CYAN << " Tests with C tab " << RESET << std::endl;
	int arr[] = { 42, 7, 13, 99, 0 };
	Span SpanArray(5);
	SpanArray.addNumber(arr, arr + 5);

	std::cout << "Contenu après addNumber(array): ";
	printSpan(SpanArray);

	std::cout << "The shortestSpan : [" << SpanArray.shortestSpan() << "]" << std::endl;
	std::cout << "The longestSpan : [" << SpanArray.longestSpan() << "]" << std::endl << std::endl;

	try {
		std::vector<int> vector2(10, 1);
		SpanArray.addNumber(vector2.begin(), vector2.end());
	}
	catch (std::exception& e) {
		std::cout << "Exception bien levée : " << e.what() << '\n';
	}

	return 0;
}
