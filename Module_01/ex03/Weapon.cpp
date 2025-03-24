#include"Weapon.hpp"

Weapon::Weapon()
{

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