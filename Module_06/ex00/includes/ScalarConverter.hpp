#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include<iostream>
#include<string>
#include <cmath>
#include <iomanip>
#include<sstream>
#include <limits>
#include<cstdlib>

/*rendre class ScalarConverter non instanciable
static convert qui permet d'etre appele sans etre instancie
    Privé ⟶ empêche les utilisateurs externes.
    Non défini ⟶ empêche de créer involontairement une instance.

Pas de decla abstraite : car A empêche d’instancier la classe elle‑même, mais pas une classe dérivée.
Pas de decla Instance : car I instanciable via une dérivée, on veut aucun objet
*/

class ScalarConverter
{
public :
	static void convert(const std::string& arg);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
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

// #ifndef SCALARCONVERTER_HPP
// # define SCALARCONVERTER_HPP

// /*Colors*/
// # define RESET "\e[0m"
// # define RED "\e[1;91m"
// # define GREEN "\e[1;92m"
// # define BLUE "\e[1;94m"
// # define YELLOW "\e[1;93m"
// # define MAGENTA "\e[1;95m"
// # define CYAN "\e[1;96m"
// # define WHITE "\e[1;97m"
// # define BLACK "\e[1;90m"
// # define GRAY "\e[1;37m"

// # include <iostream>
// # include <sstream>
// # include <iomanip>
// # include <cstdlib>
// # include <limits>

// class ScalarConverter
// {
//   private:
// 	ScalarConverter();
// 	ScalarConverter(const ScalarConverter& cpy);
// 	ScalarConverter& operator=(const ScalarConverter& cpy);
// 	~ScalarConverter();
//   public:
// 	static void convert(std::string input);
// };

// #endif
