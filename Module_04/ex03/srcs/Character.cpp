#include "Character.hpp"

Character::Character(std::string name)
{
    //Votre Character doit comporter un constructeur prenant son nom en paramètre.
}

Character::Character(const Character& copy)
{
    //Toute copie  d’un Character doit être profonde
}
Character& Character::operator=(const Character& other)
{
    //Toute copie  d’un Character doit être profonde
}

Character::~Character() {}

std::string const & Character::getName() const
{

}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{
    //La fonction membre unequip() ne doit PAS delete la Materia !
}

void Character::use(int idx, ICharacter& target)
{
    //La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
    //et passera la cible en paramètre à la fonction AMateria::use.
}