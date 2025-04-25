#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <iterator>
#include <list>

//class dériver de std::stack<T>.
//garder toutes les opérations de pile sans les réécrire.
//ajouter des itérateurs (begin(), end(), rbegin(), rend() + V const),
	//en utilisant sur le membre protected c (le conteneur sous-jacent).

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	MutantStack (){}
	MutantStack (const MutantStack& copy) : std::stack<T>(copy) {}
	MutantStack& operator=(const MutantStack& other){
		std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack(){}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#define BLACK   "\033[0;30m"
#define WHITE   "\033[0;37m"
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
