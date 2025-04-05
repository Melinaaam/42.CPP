#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	for(int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& copy) : _name(copy._name)
{
	for (int i = 0; i < 4; i++){
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
Character& Character::operator=(const Character& other)
{
	if (this != &other){
		_name = other._name;
		for (int i = 0; i < 4; i++){
			if (_inventory[i]){
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++){
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++){
		if (_inventory[i]){
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	if (!m) return;
	int i = 0;
	for (; i < 4; i++){
		if (_inventory[i] == NULL){
			_inventory[i] = m->clone();
			break ;
		}
	}
	if (m){
		delete m;
		m = NULL;
	}
	if (i == 4)
		std::cout << "The materia slots are full, you have to unequip 1 slot." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx]){
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4) {
		if (_inventory[idx])
			_inventory[idx]->use(target);
		else
			std::cout << "Slot " << idx << RED << " is empty." << RESET << std::endl;
	}
}

void Character::displayInventory() const
{
	bool empty = true;
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL) {
			empty = false;
			break;
		}
	}
	if (empty) {
		std::cout << "The inventory " << _name << RED << " is empty." << RESET << std::endl;
	} else {
		std::cout << std::endl << "Inventory of " << _name << " :" << std::endl;
		for (int i = 0; i < 4; ++i) {
			std::cout << "Slot " << i << " : ";
			if (_inventory[i] != NULL)
			std::cout << _inventory[i]->getType();
			else
				std::cout << RED << "empty" << RESET;
			std::cout << std::endl;
		}
	}
}
