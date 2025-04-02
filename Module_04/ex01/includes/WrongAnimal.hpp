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
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

    std::string getType() const;
    void makeSound() const;
};

#endif
