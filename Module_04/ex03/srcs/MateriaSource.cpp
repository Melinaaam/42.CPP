#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)	{
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

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++){
		if (_inventory[i]){
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++){
		if (_inventory[i] == NULL){
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++){
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}
void MateriaSource::displayInventory() const
{
	bool empty = true;
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL) {
			empty = false;
			break;
		}
	}

	if (empty) {
		std::cout << "The inventory " << " is empty." << std::endl;
	} else {
		std::cout << "Inventory of MateriaSource :" << std::endl;
		for (int i = 0; i < 4; ++i) {
			std::cout << "Slot " << i << " : ";
			if (_inventory[i] != NULL)
				std::cout << _inventory[i]->getType();
			else
				std::cout << "empty";
			std::cout << std::endl;
		}
	}
}
