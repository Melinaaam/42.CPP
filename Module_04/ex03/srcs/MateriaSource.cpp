#include "MateriaSource.hpp"

// En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
// afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
// partir de son type sous forme de chaîne de caractères.

MateriaSource::MateriaSource(void)
{

}

MateriaSource::MateriaSource(const MateriaSource& copy)
{

}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{

}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria*) 
{
    // Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
    // plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
    // maximum. Ces dernières ne sont pas forcément uniques.
}

AMateria* MateriaSource::createMateria(std::string const & type) 
{
    // Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
    // ment par la MateriaSource et dont le type est le même que celui passé en para-
    // mètre. Retourne 0 si le type est inconnu
}