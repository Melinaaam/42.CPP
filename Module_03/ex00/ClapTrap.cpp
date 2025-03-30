#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _fixedValue(0), _Hit(10), _Life(10), _Damage(0)
{
	std::cout << "Constructor called" << std::endl;
	//Hit points (10), representing the health of the ClapTrap
}
ClapTrap::ClapTrap(std::string name)
{
	_Name = name;
	std::cout << "ClapTrap constructor" << std::endl;
}

// ClapTrap::ClapTrap(const ClapTrap& copy)
// {
// 	std::cout << "ClapTrap(const ClapTrap& copy)" << std::endl;
// }
// ClapTrap& ClapTrap::operator=(const ClapTrap& other)
// {
// 	std::cout << "ClapTrap::operator=(const ClapTrap& other)" << std::endl;
// }

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "attack called" << std::endl;
//ClapTrap <name> attacks <target>, causing <damage> points of damage!
	std::cout << "ClapTrap " << _Name << target << ", causing" << _Damage << "points of damage!" << std::endl;
	//Attack damage (0)
	//Lorsque ClapTrap attaque, il fait perdre <dégâts d'attaque> points de vie à sa cible.
	ClapTrap::operator--(_Damage);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	(void)amount;
	std::cout << "takeDamage called" << std::endl;
	//Attack damage (0)
}
//Attaquer et réparer chacune coûte 1 point d'énergie.
//Bien sûr, ClapTrap ne peut rien faire s'il n'a plus de points de vie ni de points d'énergie
//Cependant, ces exercices servant d'introduction, les instances de ClapTrap ne doivent pas interagir directement entre elles,
//et les paramètres ne doivent pas faire référence à une autre instance de ClapTrap

void ClapTrap::beRepaired(unsigned int amount)
{
	(void)amount;
	std::cout << "beRepaired called" << std::endl;
	//Energy points (10)
	//Lorsqu'il se répare, il regagne <amount> hit points.
	ClapTrap::operator++(_Life);
	ClapTrap::operator++(_Hit);
}

ClapTrap ClapTrap::operator++(int)
{
	ClapTrap temp(*this);
	this->_fixedValue += 1;
	return temp;
}

ClapTrap ClapTrap::operator--(int)
{
	ClapTrap temp(*this);
	this->_fixedValue -= 1;
	return *this;
}


void  ClapTrap::setName(std::string name)
{
	_Name = name;
}

std::string ClapTrap::getName() const
{
	return _Name;
}
