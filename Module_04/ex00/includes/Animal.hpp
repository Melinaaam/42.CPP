#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include<string>
#include<iostream>

class Animal
{
protected:
    std::string _type;
public:
    Animal(void);
    Animal(const Animal& copy);
    Animal& operator=(const Animal& other);
    virtual ~Animal(void);

    std::string getType() const;
    virtual void makeSound() const; //virtual rends l'appel a la fonction dynamique,
                                    //le compilateur va chercher le "vrai" type pour afficher le bon message
                                    //on appel ce type de fonction : methode
};

/*COLORS*/
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;5;220m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[38;5;45m"
#define PINK    "\033[38;5;213m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

#endif
