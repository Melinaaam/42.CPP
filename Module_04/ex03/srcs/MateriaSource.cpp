#include "MateriaSource.hpp"

// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
// afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
// partir de son type sous forme de chaîne de caractères.

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
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
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
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
    // Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
    // plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
    // maximum. Ces dernières ne sont pas forcément uniques.
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;//m->clone(); //stock une copie, pas ptr direct
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
    // ment par la MateriaSource et dont le type est le même que celui passé en para-
    // mètre. Retourne 0 si le type est inconnu
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}
