#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called !" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap Constructor of " << name << " called !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap Copy constructor of  " << copy._Name << " called !" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator of " << other._Name << " called !" << std::endl;
	if (this != &other)
	{
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

std::string ClapTrap::getName(void) const { return (this->_Name); }

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called for " << _Name << " !" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoints == 0){
		std::cout<< "ClapTrap " << _Name << " has no more Energy points !" << std::endl;
		return ;}
	if (_HitPoints <= 0){
		std::cout << "ClapTrap " << _Name << " is dead !" << std::endl;
		return; }
	else{
		_EnergyPoints--;
		std::cout << "ClapTrap " << _Name << " attacks "<< target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << getName() << " loose " << amount << " points !" << std::endl;
	_HitPoints -= amount;
	if (_HitPoints < 0)
		_HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_EnergyPoints <= 0){
		std::cout << "ClapTrap " << _Name << " has no more Energy points !" << std::endl;
		return ;
	}
	if (_HitPoints <= 0){
		std::cout << "ClapTrap " << _Name << " is dead !" << std::endl;
		return; }
	
	_EnergyPoints--;
	_HitPoints += amount;
	std::cout << "ClapTrap " << _Name << " get " << amount << " energy points" << std::endl;
}

