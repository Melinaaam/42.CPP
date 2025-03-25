#include"HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << name << " construct HumanB" << std::endl;
//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed
}

void HumanB::attack()
{
    std::cout << getName() << " attacks with their " << &Weapon::getType << std::endl;
    // /<name> attacks with their <weapon type>
}
const std::string &HumanB::getName() const
{
    return _name;
}
void HumanB::setName(const std::string &newName)
{
    _name = newName;
}
void HumanB::setWeapon(Weapon Weapon)
{
    
}
HumanB::~HumanB()
{

}