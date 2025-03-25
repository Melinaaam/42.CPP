#include"HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    
    std::cout << name << " construct HumanA" << std::endl;
}
void HumanA::attack()
{
    std::cout << this->getName() << " attacks with their " << _weapon.getType() << std::endl;
}
const std::string &HumanA::getName() const
{
    return _name;
}
void HumanA::setName(const std::string &newName)
{
    _name = newName;
}

HumanA::~HumanA()
{

}