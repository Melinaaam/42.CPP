#include"Weapon.hpp"
#include"HumanA.hpp"
#include"HumanB.hpp"

//If your implementation is correct, executing the following code will print an attack
//with "crude spiked club" followed by a second attack with "some other type of club" for
//both test cases:

int main()
{
    {    
        Weapon club = Weapon(" hache ");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType(" epee ");
        bob.attack();
    }
    {    
        Weapon club = Weapon(" Arme1 ");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType(" Arme 2 ");
        jim.attack();
    }
    return 0;
}
