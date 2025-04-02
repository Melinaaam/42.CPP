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
    Animal(std::string newType);
	Animal(const Animal& copy);
	Animal& operator=(const Animal& other);
	virtual ~Animal(void);

    std::string getType() const;
    virtual void makeSound() const; //virtual rends l'appel a la fonction dynamique, 
                                //le compilateur va chercher le "vrai" type pour afficher le bon message
                                //on appel ce type de fonction : methode
};

#endif