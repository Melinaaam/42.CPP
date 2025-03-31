#include"FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "_________FragTrap : Default Constructor called !" << std::endl;
    _HitPoints = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;

}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "_________FragTrap Constructor of " << name << " called !" << std::endl;

}
FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    std::cout << "_________FragTrap Copy constructor of  " << copy._Name << " called !" << std::endl;
	*this = copy;
}
FragTrap::~FragTrap(void)
{
    std::cout << "_________FragTrap Destructor called for " << _Name << " !" << std::endl;

}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator of " << other._Name << " called !" << std::endl;
	if (this != &other)
	    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << _Name << " requests high fives, guys!" << std::endl;
}