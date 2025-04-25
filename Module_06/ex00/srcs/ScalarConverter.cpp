#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& copy){(void)copy;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){return *this; (void)other;}
ScalarConverter::~ScalarConverter(){}

enum eType { CHAR, INT, PSEUDO_FLOAT, PSEUDO_DOUBLE, FLOAT, DOUBLE, UNKNOWN };

static int isNumber(std::string input)
{
    int start(0);
    if (input[0] == '+' || input[0] == '-')
        start++;
    int len = static_cast<int>(input.size());
    if (input[input.size() - 1] == 'f')
        len--;
    int point(0);
    int nbDec(0);
    for (int i(start); i < len; i++) {
        if (input[i] == '.')
            point++;
        if (input[i] == '.' && point > 1)
            return (-1);
        if (point == 1 && input[i] >= '0' && input[i] <= '9')
            nbDec++;
        if ((input[i] < '0' || input[i] > '9') && input[i] != '.')
            return (-1);
    }
    return (nbDec);
}

void printChar(double d, bool canot) {
    std::cout << "char: ";
    if (canot || std::isnan(d) || std::isinf(d)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (c < 32 || c > 126) {
        std::cout << "Non displayable" << std::endl;
        return;
    }
    std::cout << '\'' << c << '\'' << std::endl;
}

void printInt(double d, bool canot) {
    std::cout << "int: ";
    if (canot || std::isnan(d) || std::isinf(d) ||
        d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;;
        return;
    }
    std::cout << static_cast<int>(d) << std::endl;
}

void printFloat(double d, bool pseudo, const std::string& arg, eType type) {
    std::cout << "float: ";

    float f = static_cast<float>(d);
	if (arg >= "9999999999999") {
		std::cout << "inff" << std::endl;
		return;
	}
// double dd = std::strtod(arg.c_str(), nullptr);
// if (dd > std::numeric_limits<float>::max()) {
//     std::cout << "inff\n";
//     return;
// }
// if (dd < -std::numeric_limits<float>::max()) {
//     std::cout << "-inff\n";
//     return;
// }
    // Check for infinity first
    if (std::isinf(f)) {
        std::cout << (f < 0 ? "-inff" : "inff") << std::endl;
        return;
    }

    // Check for NaN
    if (std::isnan(f)) {
        std::cout << "nanf" << std::endl;
        return;
    }

    // For pseudo-literals
    if (pseudo) {
        if (std::isnan(f)) {
            std::cout << "nanf" << std::endl;
        } else if (std::isinf(f)) {
            std::cout << (f < 0 ? "-inff" : "inff") << std::endl;
        }
        return;
    }

    // Handle scientific notation for large values
    if (std::abs(d) > 999999999.0) {
        std::ostringstream ss;
        ss.precision(0);
        ss << std::scientific << f;

        // Replace e+0xx with e+xx
        std::string s = ss.str();
        size_t pos = s.find("e+0");
        if (pos != std::string::npos)
            s.erase(pos + 2, 1);

        std::cout << s << "f" << std::endl;
        return;
    }

    // For integers
    if (type == INT) {
        std::cout << static_cast<int>(d) << ".0f" << std::endl;
        return;
    }

    // For floats
    if (type == FLOAT) {
        int prec = isNumber(arg);
        if (prec == 0) {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(prec) << f << "f" << std::endl;
        }
        return;
    }

    // For double
    if (type == DOUBLE) {
        int prec = isNumber(arg);
        if (prec == 0) {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(prec) << f << "f" << std::endl;
        }
        return;
    }

    // Default case (char)
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}


void printDouble(double d, bool pseudo, const std::string& arg, eType type) {
    std::cout << "double: ";
	if (arg >= "9999999999999") {
		std::cout << "inf" << std::endl;
		return;
	}
    if (std::isinf(d)) {
        std::cout << (d < 0 ? "-inf" : "inf") << std::endl;
        return;
    }

    if (std::isnan(d)) {
        std::cout << "nan" << std::endl;
        return;
    }

    if (pseudo) {
        if (std::isnan(d)) {
            std::cout << "nan" << std::endl;
        } else if (std::isinf(d)) {
            std::cout << (d < 0 ? "-inf" : "inf") << std::endl;
        }
        return;
    }

    if (std::abs(d) > 1e+10) {
        std::ostringstream ss;
        ss << std::scientific << std::setprecision(0) << d;
        std::string result = ss.str();
        // Remove the leading "1." and adjust the exponent
        if (result.find("e") != std::string::npos) {
            result = result.substr(0, 1) + "e" + std::to_string(std::stoi(result.substr(result.find("e") + 1)) + 1);
        }
        std::cout << result << std::endl;
        return;
    }
    if (type == INT) {
        std::cout << static_cast<int>(d) << ".0" << std::endl;
        return;
    }

    if (type == FLOAT) {
        int prec = isNumber(arg);
        if (prec == 0) {
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(prec) << d << std::endl;
        }
        return;
    }

    if (type == DOUBLE) {
        int prec = isNumber(arg);
        if (prec == 0) {
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(prec) << d << std::endl;
        }
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}




bool isInt(const std::string& s) {
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    if (i == s.size())
        return false;
    for (; i < s.size(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool isFloat(const std::string& s) {
    if (s.size() < 2 || s[s.size() - 1] != 'f')
        return false;
    bool point = false;
    bool OneDigit = false;
    size_t i = 0;
    if(s[i] == '+' || s[i] == '-')
        ++i;
    for(;i + 1 < s.size(); ++i) {
        unsigned char c = s[i];
        if(c == '.'){
            if (point)
                return false;
            point = true;
        }
        else if (isdigit(c)) {
            OneDigit = true;
        }
        else
            return false;
    }
    return point && OneDigit;
}

bool isDouble(const std::string& s) {
    if(s.size() < 2)
        return false;
    bool point = false;
    bool OneDigit = false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for(;i < s.size(); ++i) {
        unsigned char c = s[i];
        if (c == '.') {
            if (point)
                return false;
            point = true;
        }
        else if (isdigit(c)) {
            OneDigit = true;
        }
        else
            return false;
    }
    return point && OneDigit && isdigit(static_cast<unsigned char>(s[s.size()-1]));
}

eType detectType(const std::string& arg)
{
    if (arg.length() == 1 && !isdigit(arg[0]))
        return CHAR;
    if (arg == "+inff" || arg == "-inff" || arg == "nanf" || arg == "inff")
        return PSEUDO_FLOAT;
    if (arg == "+inf" || arg == "-inf" || arg == "nan" || arg == "inf")
        return PSEUDO_DOUBLE;
    if (isInt(arg))
        return INT;
    if (isFloat(arg))
        return FLOAT;
    if (isDouble(arg))
        return DOUBLE;
    else
        return UNKNOWN;
}

bool checkIntOverflow(const std::string& arg) {
    errno = 0;
    char* endptr;
    long l = std::strtol(arg.c_str(), &endptr, 10);

    if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) {
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string& arg)
{
    eType type = detectType(arg);

    double double_val = 0.0;
    float float_val = 0.0f;
    bool pseudo = false;
    bool overflow = false;

    switch (type)
    {
        case CHAR: {
            double_val = static_cast<double>(arg[0]);
            float_val = static_cast<float>(double_val);
            break;
        }
        case INT: {
            overflow = checkIntOverflow(arg);
            // Toujours convertir en double pour obtenir la valeur correcte
            double_val = strtod(arg.c_str(), NULL);
            float_val = static_cast<float>(double_val);
            break;
        }
        case PSEUDO_FLOAT: {
            float_val = strtof(arg.c_str(), NULL);
            double_val = static_cast<double>(float_val);
            pseudo = true;
            break;
        }
        case PSEUDO_DOUBLE: {
            double_val = strtod(arg.c_str(), NULL);
            float_val = static_cast<float>(double_val);
            pseudo = true;
            break;
        }
        case FLOAT: {
            float_val = strtof(arg.c_str(), NULL);
            double_val = static_cast<double>(float_val);
            break;
        }
        case DOUBLE: {
            double_val = strtod(arg.c_str(), NULL);
            float_val = static_cast<float>(double_val);
            break;
        }
        case UNKNOWN: {
            std::cout << "char: impossible" << std::endl
                     << "int: impossible" << std::endl
                     << "float: impossible" << std::endl
                     << "double: impossible" << std::endl;
            return;
        }
    }
    if (type == INT && (arg.length() > 10 || overflow)) {
        if (double_val > std::numeric_limits<int>::max() ||
            double_val < std::numeric_limits<int>::min()) {
            overflow = true;
        }
    }

    printChar(double_val, overflow);
    printInt(double_val, overflow);
    printFloat(double_val, pseudo, arg, type);
    printDouble(double_val, pseudo, arg, type);
}

