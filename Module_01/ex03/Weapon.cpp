#include"Weapon.hpp"

Weapon::Weapon(std::string name)
{
    // _type = " hache ";
    std::cout << name << " create "<< std::endl;
}
const std::string &Weapon::getType() const
{
    // std::cout << "in getType : " << _type << std::endl;
    return _type;
    //retourne le type d'arme
}
void Weapon::setType(const std::string &newType)
{
    _type = newType;
    //param le type d'arme dans la string passe en param pour pvr la param
}

Weapon::~Weapon()
{

}