#include "Span.hpp"

Span::Span() : _n(0), _values() {}

Span::Span(unsigned int n) : _n(n), _values() {  } //.reserve evite toute realloc inutile si on connait n elmts a push basck

Span::Span (const Span& copy) : _n(copy._n), _values(copy._values){}

Span& Span::operator=(const Span& other)
{
	if (this != &other){
		_n = other._n;
		_values = other._values;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int nb){
	if (_values.size() >= _n)
		throw std::runtime_error("\033[0;31m Span is already full \033[0m");
	_values.push_back(nb);
}

int Span::shortestSpan() const {
	if (_values.size() < 2)
		throw std::runtime_error("\033[0;31m Not enough numbers to find a span \033[0m");
//Parcourir les éléments triés, calculer la différence adjacente la plus petite
	std::vector<int> tmp = _values;
	std::sort(tmp.begin(), tmp.end());
	int minDiff = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); ++i) {
		int diff = tmp[i] - tmp[i-1];
		if (diff < minDiff)
		minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() const {
	if (_values.size() < 2)
		throw std::runtime_error(" \033[0;31mNot enough numbers to find a span \033[0m");
	std::vector<int>::const_iterator minIt =
		std::min_element(_values.begin(), _values.end());
	std::vector<int>::const_iterator maxIt =
		std::max_element(_values.begin(), _values.end());
	return *maxIt - *minIt;
}
