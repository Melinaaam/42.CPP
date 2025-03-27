#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>
#include<string>
#include<cmath>

class Fixed{
private:
    int _fixedValue; 
    static int const _fractBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed& copy);
    Fixed(const int i);
    Fixed(const float f);
    Fixed& operator=(const Fixed& copy);
    ~Fixed(void);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int toInt( void ) const;
    float toFloat( void ) const;

    //Add public member functions to your class to overload the following operators:
        // The 6 comparison operators: >, <, >=, <=, ==, and !=.
        // • The 4 arithmetic operators: +, -, *, and /.
        // • The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
        // post-decrement) operators, which will increase or decrease the fixed-point value by
        // the smallest representable ϵ, such that 1 + ϵ > 1.
    //Add these four public overloaded member functions to your class:
        // A static member function min that takes two references to fixed-point numbers as
        // parameters, and returns a reference to the smallest one.
        // • A static member function min that takes two references to constant fixed-point
        // numbers as parameters, and returns a reference to the smallest one.
        // • A static member function max that takes two references to fixed-point numbers as
        // parameters, and returns a reference to the greatest one.
        // • A static member function max that takes two references to constant fixed-point
        // numbers as parameters, and returns a reference to the greatest one.
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

// Créez une classe sous forme canonique pour représenter un nombre à virgule fixe.
// • Membres privés :
// ◦ Un entier pour stocker la valeur du nombre en virgule fixe.
// ◦ Un entier constant statique pour stocker le nombre de bits de la partie
// fractionnaire, et dont la valeur sera toujours le littéral entier 8.
// • Membres publics :
// ◦ Un constructeur par défaut qui initialisera la valeur du nombre à virgule fixe
// à 0.
// ◦ Un constructeur de recopie.
// ◦ Une surcharge de l’opérateur d’affectation.
// ◦ Un destructeur.
// ◦ Une fonction membre int getRawBits( void ) const;
// qui retourne la valeur du nombre à virgule fixe sans la convertir.
// ◦ Une fonction membre void setRawBits( int const raw );
// qui initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.