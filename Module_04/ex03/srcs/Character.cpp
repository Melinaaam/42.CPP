#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
    //Votre Character doit comporter un constructeur prenant son nom en paramètre.
	for(int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& copy) : _name(copy._name)
{
    //Toute copie d’un Character doit être profonde dc de _name et inventory
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}
Character& Character::operator=(const Character& other)
{
    //Toute copie  d’un Character doit être profonde
	// Opérateur d'affectation (deep copy) : supprime l'inventaire existant et clone celui de l'objet source
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = nullptr;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	//ajoute une Materia dans le premier emplacement vide de l'inventaire
	if (!m) return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			break ;//stop des que m est equipe
		}
	}
}

void Character::unequip(int idx)
{
    //La fonction membre unequip() ne doit PAS delete la Materia !
	//retire la Materia de l'emplacement idx sans la delete
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx] = nullptr;
	//PAS OUBLIER DELETE AILLEURS
}

void Character::use(int idx, ICharacter& target)
{
    //La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
    //et passera la cible en paramètre à la fonction AMateria::use.
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr)
		_inventory[idx]->use(target);
}
