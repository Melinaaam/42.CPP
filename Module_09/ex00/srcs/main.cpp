#include <BitcoinExchange.hpp>

/*
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
*/

std::string cleanWhitespace(const std::string& str) {
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if (start == std::string::npos || end == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

bool parseValue(const std::string& valueStr, double& value) {
	std::istringstream stream(valueStr);
	stream >> value;
	return !stream.fail();
}

bool isValidDateFormat(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i])) return false;
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	BitcoinExchange btc("data.csv");
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, valueStr;
		if (!(std::getline(ss, date, '|') && std::getline(ss, valueStr))) {
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		date = cleanWhitespace(date);
		valueStr = cleanWhitespace(valueStr);
		if (!isValidDateFormat(date)) {
			std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
			continue;
		}
		double value;
		if (!parseValue(valueStr, value)) {
			std::cerr << RED << "Error: bad input => " << valueStr << RESET << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << RED << "Error: too large a number." << RESET << std::endl;
			continue;
		}
		double goodPrice = btc.getpriceByDate(date);
		if (goodPrice < 0)
			continue;
		double result = goodPrice* value;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
	return 0;
}
