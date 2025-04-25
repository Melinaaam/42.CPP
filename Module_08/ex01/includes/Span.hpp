#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<string>
#include <vector>
#include <algorithm> // std::sort, std::minmax_element
#include <iterator> // std::distance
#include <stdexcept> // std::runtime_error

class Span {
private :
	unsigned int		_n;
	std::vector<int>	_values;
public:
	Span();
	Span(unsigned int n);
	Span (const Span& copy);
	Span& operator=(const Span& other);
	~Span();

	template<typename InputIt>
	void addNumber(InputIt begin, InputIt end);

	void addNumber(int nb);
	int shortestSpan() const;
	int longestSpan() const;

	std::vector<int>::const_iterator begin() const { return _values.begin(); }
	std::vector<int>::const_iterator end()   const { return _values.end(); }

};

template<typename InputIt>
void Span::addNumber(InputIt begin, InputIt end) {
	std::size_t rangeSize = static_cast<std::size_t>(std::distance(begin, end));
	if (_values.size() + rangeSize > _n)
		throw std::runtime_error("\033[0;31m Not enough space to insert range \033[0m");
    _values.insert(_values.end(), begin, end);
}

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;5;220m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35;1m"
#define MAGENTA1 "\033[0;35;2m"
#define MAGENTA2 "\033[0;35;4m"
#define CYAN    "\033[38;5;45m"
#define PINK    "\033[38;5;213m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"
#define CLIGNOTE "\033[0;35;5m"
#define UNDER_	"\x1b[4m"

#endif
