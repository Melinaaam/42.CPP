#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include<string>
#include<iostream>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal(void);
    WrongAnimal(std::string newType);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

    std::string getType() const;
    virtual void makeSound() const; //virtual rends l'appel a la fonction dynamique, 
                                //le compilateur va chercher le "vrai" type pour afficher le bon message
                                //on appel ce type de fonction : methode
};

#endif
