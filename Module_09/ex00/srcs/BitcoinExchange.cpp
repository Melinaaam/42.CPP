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

static bool isValidDateFormat(const std::string& date) {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	return true;
}

BitcoinExchange::BitcoinExchange(const std::string& file) {loadDatabase(file);}


float BitcoinExchange::getpriceByDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _priceByDate.lower_bound(date);
	if (it != _priceByDate.end() && it->first == date)
		return it->second;
	if (it != _priceByDate.begin())
		return (--it)->second;
	throw std::runtime_error("No rate available for the given date.");
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
		float value;
		if (std::getline(ss, date, ',') && std::getline(ss, valueStr)){
			if (!isValidDateFormat(date))
				continue;
			value = static_cast<float>(atof(valueStr.c_str()));
			_priceByDate[date] = value;
		}
	}
	file.close();
}
std::map<std::string, float> _priceByDate;
