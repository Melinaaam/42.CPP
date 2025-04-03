#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"ICharacter.hpp"

class Character : public ICharacter
{
public:
// Votre Character doit comporter un constructeur prenant son nom en paramètre.
    Character(std::string name);
	Character(const Character& copy);
	Character& operator=(const Character& other);
    ~Character() {}

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif