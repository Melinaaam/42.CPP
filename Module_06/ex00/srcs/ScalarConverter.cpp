#include "ScalarConverter.hpp"

//nan : pas un nb, valeur numerique impossible a identifier
//+inf : infini pos
// -inf : infini neg

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

void printFloat(double d, bool pseudo, const std::string& arg, eType type, bool overflowInt, bool overflowFloat) {
    std::cout << "float: ";

    float f = static_cast<float>(d);
    if (overflowInt)
    {
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<float>(d) << "f\n";
        return;
    }
    if (pseudo) {
        if (std::isnan(f)) {
            std::cout << "nanf" << std::endl;
        } else if (std::isinf(f)) {
            std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
        }
        return;
    }
    if (type == INT) {
        std::cout << std::fixed << std::setprecision(1) << static_cast<int>(d) << ".0f" << std::endl;
        return;
    }
    if (type == FLOAT) {
        int prec = isNumber(arg);
        if (prec == 0) {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(prec) << f << "f" << std::endl;
        }
        return;
    }
    if (overflowFloat)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (type == DOUBLE) {
        int prec = isNumber(arg);
        if (prec == 0) {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(prec) << f << "f" << std::endl;
        }
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble(double d, bool pseudo, const std::string& arg, eType type, bool overflowDouble) {
    std::cout << "double: ";
    if (overflowDouble)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (pseudo) {
        if (std::isnan(d)) {
            std::cout << "nan" << std::endl;
        } else if (std::isinf(d)) {
            std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
        }
        return;
    }
    if (type == INT) {
        std::cout << arg << ".0" << std::endl;
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

void ScalarConverter::convert(const std::string& arg)
{
    eType type = detectType(arg);

    double double_val       = 0.0;
    float float_val         = 0.0f;
    bool pseudo             = false;
    bool    overflowInt     = false;
    bool    overflowFloat   = false;
    bool    overflowDouble  = false;

    switch (type)
    {
        case CHAR: {
            double_val = static_cast<double>(arg[0]);
            float_val = static_cast<float>(double_val);
            break;
        }
        case INT: {
            char* endptr = NULL;
            long l = std::strtol(arg.c_str(), &endptr, 10);
            if (*endptr != '\0' ||
                l > std::numeric_limits<int>::max() ||
                l < std::numeric_limits<int>::min())
                overflowInt = true;
            double_val = static_cast<double>(l);
            float_val  = static_cast<float>(double_val);
            break;
        }
        case PSEUDO_FLOAT: {
            char* endptr = NULL;
            float f = std::strtof(arg.c_str(), &endptr);
            if (*endptr != '\0')
                overflowFloat = true;
            float_val  = f;
            double_val = static_cast<double>(f);
            break;
        }
        case PSEUDO_DOUBLE: {
            double_val = std::strtod(arg.c_str(), NULL);
            float_val  = static_cast<float>(double_val);
            pseudo     = true;
            break;
        }
        case FLOAT: {
            char* endptr;
            float f = std::strtof(arg.c_str(), &endptr);
            if (*endptr != '\0')
                overflowFloat = true;
            float_val  = f;
            double_val = static_cast<double>(f);
            break;
        }
        case DOUBLE: {
            char* endptr;
            double d = std::strtod(arg.c_str(), &endptr);
            if (*endptr != '\0')
                overflowDouble = true;
            double_val = d;
            float_val  = static_cast<float>(d);
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
    printChar   (double_val, overflowInt);
    printInt    (double_val, overflowInt);
    printFloat  (float_val, pseudo, arg, type, overflowInt, overflowFloat);
    printDouble (double_val, pseudo, arg, type, overflowDouble);
}

