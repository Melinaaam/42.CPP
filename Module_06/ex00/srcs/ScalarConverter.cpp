#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& copy){(void)copy;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){return *this; (void)other;}
ScalarConverter::~ScalarConverter(){}

enum eType {CHAR, INT, PSEUDO_FLOAT, PSEUDO_DOUBLE, FLOAT, DOUBLE, UNKNOWN };

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

static void printChar(double d, bool canot) {
    std::cout << "char : ";
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

static void printInt(double d, bool canot, const std::string& arg, eType type) {
    std::cout << "int : ";
    std::stringstream backToString;
    std::string    inputWithoutF;
    if (arg[arg.size() - 1] == 'f')
        inputWithoutF = arg.substr(0, arg.size() - 1);
    else
        inputWithoutF = arg;
    if (isNumber(arg) == 0)
        backToString << std::fixed << std::setprecision(0) << d;
    else if (isNumber(arg) > 0)
        backToString << std::fixed << std::setprecision(isNumber(arg)) << d;
    else
        backToString << d;
    if (backToString.str() != inputWithoutF && type != CHAR)
        std::cout << "impossible" << std::endl;
    else if (canot || std::isnan(d) || std::isinf(d)) 
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double f, bool pseudo, const std::string& arg, eType type) {
    std::cout << "float : ";
    std::stringstream backToString;
    std::string    inputWithoutF;
    if (arg[arg.size() - 1] == 'f')
        inputWithoutF = arg.substr(0, arg.size() - 1);
    else
        inputWithoutF = arg;
    if (isNumber(arg) == 0)
        backToString << std::fixed << std::setprecision(0) << f;
    else if (isNumber(arg) > 0)
        backToString << std::fixed << std::setprecision(isNumber(arg)) << f;
    else
        backToString << f;
    if (backToString.str() != inputWithoutF && type != CHAR && pseudo == false)
        std::cout << "impossible";
    else if (pseudo) {
        if (std::isnan(f))      
            std::cout << "nanf";
        else if (std::isinf(f)) {
            if (f < 0)
                std::cout << "-inff";
            else
                std::cout << "+inff";
        }
    }
    else {
        if (!isNumber(arg) || type == CHAR)
            std::cout << std::fixed << std::setprecision(1) << f << "f";
        else
            std::cout << std::fixed << std::setprecision(isNumber(arg)) << f << "f";
    }
    std::cout << std::endl;
}

static void printDouble(double d, bool pseudo, const std::string& arg, eType type) {
    std::cout << "double : ";
    std::stringstream backToString;
    std::string    inputWithoutF;
    if (arg[arg.size() - 1] == 'f')
        inputWithoutF = arg.substr(0, arg.size() - 1);
    else
        inputWithoutF = arg;
    if (isNumber(arg) == 0)
        backToString << std::fixed << std::setprecision(0) << d;
    else if (isNumber(arg) > 0)
        backToString << std::fixed << std::setprecision(isNumber(arg)) << d;
    else
        backToString << d;
    if (backToString.str() != inputWithoutF && type != CHAR && pseudo == false)
        std::cout << "impossible" << std::endl;
    else if (pseudo) {
        if (std::isnan(d))      
            std::cout << "nan" << std::endl;
        else if (std::isinf(d)) {
            if (d < 0)
                std::cout << "-inf" << std::endl;
            else
                std::cout << "+inf" << std::endl;
        }
    }
    else {
        if (!isNumber(arg) || type == CHAR)
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        else
            std::cout << std::fixed << std::setprecision(isNumber(arg)) << d << std::endl;
    }
}

static bool isInt(const std::string& s)
{
    if (s.empty())
        return false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    if (i == s.size())
        return false;
    for (; i < s.size(); i++){
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string& s) { 
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
        else if (isdigit(static_cast<unsigned char>(c))) {
            OneDigit = true;   
        }
        else   
            return false;
    }
    return point && OneDigit;
}

static bool isDouble(const std::string& s) {
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
        else if (isdigit(static_cast<unsigned char>(c))) {
            OneDigit = true;
        }
        else 
            return false;
    }
    return point && OneDigit && isdigit(static_cast<unsigned char>(s[s.size()-1]));
}

static eType detectType(const std::string& arg)
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
/*Les fonctions C (strtod, strtof) savent déjà les transformer en vrai NaN ou Inf. */
void ScalarConverter::convert(const std::string& arg)
{
    eType type = detectType(arg);
    double double_val = 0.0;
    float  float_val = 0.0f;
    bool   overflow = false;
    bool   pseudo   = false;
    switch (type)
    {
        case CHAR : {
            double_val = static_cast<double>(arg[0]);
            float_val = static_cast<float>(double_val);
            break;
        }
        case INT : {
            long l = strtol(arg.c_str(), NULL, 10);
            if (l < std::numeric_limits<int>::min() ||
                l > std::numeric_limits<int>::max())
                overflow = true;
            double_val = static_cast<double>(l);
            float_val = static_cast<float>(l);
            break;
        } 
        case PSEUDO_FLOAT : {
            float_val = strtof(arg.c_str(), NULL);
            double_val = static_cast<double>(float_val);
            pseudo = true;
            overflow = true;
            break;
        }
        case PSEUDO_DOUBLE :{
            double_val = strtod(arg.c_str(), NULL);
            float_val = static_cast<float>(double_val);
            pseudo = true;
            overflow = true;
            break;
        }
        case FLOAT : {
            float_val = strtof(arg.c_str(), NULL);
            double_val = static_cast<double>(float_val);
            break;
        }
        case DOUBLE : {
            double_val = strtod(arg.c_str(), NULL);
            float_val = static_cast<float>(double_val);
            break;
        }
        case UNKNOWN : {
            std::cout << "Error: literal not recognized" << std::endl;
            break;
        }
    }
    printChar(double_val, overflow);
    printInt(double_val, overflow, arg, type);
    printFloat(float_val, pseudo, arg, type);
    printDouble(double_val, pseudo, arg, type);
}