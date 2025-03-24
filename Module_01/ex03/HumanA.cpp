#include"HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA()
{
//While HumanA takes the Weapon in its constructor, HumanB does not.//While HumanA takes the Weapon in its constructor, HumanB does not.
//HumanB may not always have a weapon, whereas HumanA will always be armed
}
void HumanA::attack()
{
    std::cout >> Weapon::getType() >> "attacks with their" >> Weapon::
    // /<name> attacks with their <weapon type>
    //<weapon type> sera remplacé par le type d'arme, obtenu via la méthode getType() de la classe Weapon.
}

HumanA::~HumanA()
{

}