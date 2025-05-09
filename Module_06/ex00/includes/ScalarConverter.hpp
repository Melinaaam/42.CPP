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