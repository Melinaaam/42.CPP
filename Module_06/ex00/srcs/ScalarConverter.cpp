#include "ScalarConverter.hpp"
/*ne sert a rien mais la au cas ou : forme canonique ?*/
// ScalarConverter::ScalarConverter(){}
// ScalarConverter::ScalarConverter(const ScalarConverter& copy){}
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){}
// ScalarConverter::~ScalarConverter(){}

bool isInt(const std::string& s)
{
    if (s.empty())
        return false;

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    if (s.size() == 1)
        return false;
    for (; i < s.size(); i++){
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}


//nan : not a number
//+inf : infini pos
//-inf : infini neg 
    //pseudo litteraux speciaux

enum eType 
{
    CHAR,
    INT,
    // FLOAT,
    // DOUBLE,
    PSEUDO_FLOAT,
    PSEUDO_DOUBLE,
    UNKNOWN
};

eType detectType(const std::string& arg)
{
    if (arg.length() == 1 && !isdigit(arg[0]))
        return CHAR;
    if (arg == "+inff" || arg == "-inff" || arg == "nanf")
        return PSEUDO_FLOAT;
    if (arg == "+inf" || arg == "-inf" || arg == "nan")
        return PSEUDO_DOUBLE;
    if (isInt(arg)) //[+|-]?[0-9]+
        return INT;
        // if ([+|-]?[0-9]+.[0-9]+ )
        //     return DOUBLE;

    // if ([+|-]?[0-9]+.[0-9]+f )
    //     return FLOAT;
    
    else 
        return UNKNOWN;

}

/*Les fonctions C (strtod, strtof) savent déjà les transformer en vrai NaN ou Inf. */
void ScalarConverter::convert(const std::string& arg)
{
    eType type = detectType(arg);
    switch (type)
    {
        case CHAR : 
            std::cout << "char : " << std::endl;
            //Cas “un seul caractère”
        case INT : std::cout << "int : " << std::endl;//Entier décimal
        // case FLOAT ://Réel en float
        // case DOUBLE ://Réel en double
    
        case PSEUDO_DOUBLE :
            std::cout << "pseudo double" << std::endl;
            //Pseudo‑littéraux
        case PSEUDO_FLOAT : std::cout << "pseudo float" << std::endl;
        case UNKNOWN :
            std::cout << "Error: literal not recognized" << std::endl;
        //Sinon : type inconnu → affiche un message d’erreur et sors.

    }
}