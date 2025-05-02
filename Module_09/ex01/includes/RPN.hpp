#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<string>
#include<stack>
#include <exception>
#include <sstream>
#include <cstdlib>

class RPN{
public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN &other);
	~RPN();
	void evaluate(const std::string& expression);
	class RPNException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Invalid RPN expression";
	}
};
private:
	std::stack<int> _stack;
};

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
