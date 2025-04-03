#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include"AMateria.hpp"

class MateriaSource
{
public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& copy);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource() {}
    
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif