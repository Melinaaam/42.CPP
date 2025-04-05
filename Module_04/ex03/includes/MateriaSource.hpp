#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include"AMateria.hpp"
#include"IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _inventory[4];
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	void displayInventory() const;
};

#endif
