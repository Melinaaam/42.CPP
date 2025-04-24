#ifndef ARRAY_HPP
#define ARRAY_HPP
#include<iostream>
#include<string>
#define MAX_VAL 600

template <typename T>
class Array
{
private:
	T* _array;
	unsigned int _n;
public:
	Array() : _array(NULL), _n(0) {}

	Array(unsigned int n) {_n = n; _array = new T[n]();	}

	Array(const Array& copy): _array(NULL), _n(0)  {*this = copy;}

	Array &operator=(const Array& other) {
		if (this != &other) {
			if (_array != NULL) {
				delete [] _array;
				_array = NULL;
			}
			_n = other._n;
			if (_n > 0) {
				_array = new T[other._n];
				for (unsigned int i(0); i < _n; i++)
					_array[i] = other._array[i];
			}
		}
		return *this;
	}

	~Array(){ delete [] _array;}

	T& operator[](unsigned int idx) {
		if (idx >= _n)
			throw indexBounds();
		return this->_array[idx];
	}

	const T& operator[](unsigned int idx) const {
		if (idx >= _n)
			throw indexBounds();
		return _array[idx];
	}

	unsigned int size() const { return _n; }

	class indexBounds : public std::exception {
		virtual const char* what() const throw(){
			return "the index is out of bounds";
		}
	};
};
template <typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& arr)
{
	os << "\033[0;35;1m display array : \033[0m" << std::endl;
	for (unsigned int i = 0; i < arr.size(); ++i)
		os << "index[" << i << "] = " << arr[i] << std::endl;
	return os;
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
