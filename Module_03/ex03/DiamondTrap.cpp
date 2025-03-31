#include"DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    ClapTrap::_Name = _Name + "_clap_name";
    this->_HitPoints = FragTrap::_HitPoints;
    this->_EnergyPoints = ScavTrap::_EnergyPoints;
    this->_AttackDamage = FragTrap::_AttackDamage;

    std::cout << "---DiamondTrap default constructor called for " << _Name << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _Name = name;
    std::cout << "---DiamondTrap constructor called for " << _Name << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "---DiamondTrap Copy constructor of  " << copy._Name << " called !" << std::endl;
	*this = copy;
}
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "---DiamondTrap Destructor called for " << _Name << " !" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator of " << other._Name << " called !" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _Name = other._Name;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "_Name private of DiamondTrap: " << _Name << "&&" << std::endl;
    std::cout << "_Name private of ClapTrap: " << ClapTrap::_Name << "&&" << std::endl;
}
