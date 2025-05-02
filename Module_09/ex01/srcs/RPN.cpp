#include"RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {_stack = copy._stack;}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && std::isdigit(token[0])) {
			_stack.push(token[0] - '0');
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_stack.size() < 2)
				throw RPNException();

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int result;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else if (token == "/") {
				if (b == 0)
					throw RPNException();
				result = a / b;
			}
			_stack.push(result);
		}
		else {
			throw RPNException();
		}
	}
	if (_stack.size() != 1)
		throw RPNException();
	std::cout << _stack.top() << std::endl;
}

