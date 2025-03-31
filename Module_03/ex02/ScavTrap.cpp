#include"ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "******* ScavTrap : Default Constructor called !" << std::endl;
    _HitPoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "******* ScavTrap Constructor of " << name << " called !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    std::cout << "******* ScavTrap Copy constructor of  " << copy._Name << " called !" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "******* ScavTrap Destructor called for " << _Name << " !" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator of " << other._Name << " called !" << std::endl;
	if (this != &other)
	    ClapTrap::operator=(other);
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScrapTrap " << _Name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_EnergyPoints == 0) {
        std::cout << "ScavTrap " << _Name << " has no more Energy points !" << std::endl;
        return;
    }
    if (_HitPoints <= 0) {
        std::cout << "ScavTrap " << _Name << " is dead !" << std::endl;
        return;
    }
    _EnergyPoints--;
    std::cout << "ScavTrap " << _Name << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}