#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {*this = copy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_priceByDate = other._priceByDate;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& file) {loadDatabase(file);}

double BitcoinExchange::getpriceByDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _priceByDate.lower_bound(date);

	if (it != _priceByDate.end() && it->first == date)
		return it->second;
	if (it == _priceByDate.begin()) {
		std::cerr << RED << "Error: no price available for " << date << RESET << std::endl;
		return -1;
	}
	--it;
	return it->second;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw FailOpenFile();
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, valueStr;
		double value;
		if (std::getline(ss, date, ',') && std::getline(ss, valueStr)){
			value = static_cast<double>(atof(valueStr.c_str()));
			_priceByDate[date] = value;
		}
	}
	file.close();
}
const char* BitcoinExchange::FailOpenFile::what() const throw() {
	return "Error: could not open database file.";
}
