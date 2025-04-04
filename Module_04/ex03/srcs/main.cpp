#include"AMateria.hpp"
#include"Character.hpp"
#include"Cure.hpp"
#include"Ice.hpp"
#include"ICharacter.hpp"
#include"IMateriaSource.hpp"
#include"MateriaSource.hpp"

/*
class purement abstraites sont communément appelées des interfaces.
class abstraites : au moins une fonction virtual definie/ NE PEUT ETRE INSTANCIEE
class concretes : PEUT ETRE INSTANCIEE et dont toutes les methodes sont definies : elle est autonome
*/
// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

int main()
{
    // std::cout << CYAN << "=== Materia Source Creation and Learning ===" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // Tentative d'ajouter une troisième Materia (l'inventaire ne doit contenir que 4 modèles maximum)
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // std::cout << std::endl << YELLOW << "=== Character Creation ===" << RESET << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << std::endl << CYAN << "=== Equipping Materias to 'me' ===" << RESET << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // Ajoutons deux autres pour tester la limite de l'inventaire
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // Tentative d'équiper une cinquième Materia : cela ne devrait rien faire
    tmp = src->createMateria("ice");
    me->equip(tmp);

    std::cout << std::endl << YELLOW << "=== Testing use() of Materias on 'bob' ===" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        me->use(i, *bob);
    // Test d'utilisation avec un index invalide (aucune action attendue)
    me->use(4, *bob);

    std::cout << std::endl << GREEN << "=== Unequipping Materia ===" << RESET << std::endl;
    // Déséquipe la Materia à l'index 1 (ne la delete pas, elle reste "au sol")
    me->unequip(1);
    // me->use(1, *me);
    // Tente d'utiliser à nouveau la slot déséquipée : rien ne doit se passer
    me->use(1, *bob);

    std::cout << std::endl << CYAN << "=== Deep Copy Test ===" << RESET << std::endl;
    if (dynamic_cast<Character*>(me)) //protege le cast si il est != (ex si me n'est pas un charactere, dynamic cast renvoi null)
    { 
        Character* original = dynamic_cast<Character*>(me);
        Character* copy = new Character(*original);
        
        std::cout << YELLOW << "Original character '" << original->getName() << "' uses materias:" << RESET << std::endl;
        for (int i = 0; i < 4; i++)
        original->use(i, *bob);
        
        std::cout << YELLOW << "Copied character '" << copy->getName() << "' uses materias:" << RESET << std::endl;
        for (int i = 0; i < 4; i++)
        copy->use(i, *bob);
        std::cout << std::endl << GREEN << "=== Cleaning Up ===" << RESET << std::endl;
        delete copy;
    }
    // delete bob;
    delete me;
    delete src;

    IMateriaSource* srcM = new MateriaSource();
    if (dynamic_cast<MateriaSource*>(srcM)) {
        MateriaSource* originalM = dynamic_cast<MateriaSource*>(srcM);
        MateriaSource* copyM = new MateriaSource(*originalM);
        ICharacter* meM = new Character("meM");
        std::cout << std::endl;
        
        AMateria* tmpM;
        originalM->learnMateria(new Ice());
        std::cout << std::endl;
        
        tmpM = originalM->createMateria("ice");
        std::cout << std::endl;
        
        meM->equip(tmpM);
        std::cout << std::endl;
        
        originalM->learnMateria(new Cure());
        tmpM = originalM->createMateria("cure");
        meM->equip(tmpM);
        meM->use(0, *bob);
        meM->use(1, *bob);
        meM->use(2, *bob);
        delete copyM;
        delete meM;
    }
    delete srcM;
    delete bob;
    
    std::cout << std::endl;
    return 0;
}
