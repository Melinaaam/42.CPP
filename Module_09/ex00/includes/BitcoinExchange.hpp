#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<map>
#include<string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange(const std::string& file);
	float getpriceByDate(const std::string& date) const;


	class FailOpenFile: public std::exception {
		public:
			virtual const char *what() const throw();
	};

private:
	std::map<std::string, float> _priceByDate;
	void loadDatabase(const std::string& filename);
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
