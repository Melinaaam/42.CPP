#include"DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    _Name = "";
    ClapTrap::_Name = _Name + "_clap_name";
    _HitPoints = FragTrap::_HitPoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
    std::cout << "---DiamondTrap default constructor called for " << _Name << std::endl;
}
DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _Name = name;
    std::cout << "---DiamondTrap constructor called for " << _Name << std::endl;
    _HitPoints = FragTrap::_HitPoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
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
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _Name = other._Name;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Name private of DiamondTrap: " << _Name << std::endl;
    std::cout << "Name private of ClapTrap: " << ClapTrap::_Name << std::endl;
}