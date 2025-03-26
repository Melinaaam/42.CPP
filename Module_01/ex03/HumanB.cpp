#include"HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{

}

void HumanB::attack()
{
    if(_weapon == NULL)
        std::cout << getName() << " don't have any weapon " << std::endl;
    else
        std::cout << getName() << " attacks with their " << _weapon->getType() << std::endl;
}
const std::string &HumanB::getName() const
{
    return _name;
}
void HumanB::setName(const std::string &newName)
{
    _name = newName;
}
void HumanB::setWeapon(Weapon &Weapon)
{
    _weapon = &Weapon;
}
HumanB::~HumanB()
{
    
}