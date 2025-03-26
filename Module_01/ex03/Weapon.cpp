#include"Weapon.hpp"

Weapon::Weapon(std::string name)
{
    _type = name;
}
const std::string &Weapon::getType() const
{
    return _type;
}
void Weapon::setType(const std::string &newType)
{
    _type = newType;
}

Weapon::~Weapon()
{

}