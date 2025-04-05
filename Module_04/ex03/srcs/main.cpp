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
	std::cout << CYAN << "=== Creation and learn of Materia source ===" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	dynamic_cast<MateriaSource*>(src)->displayInventory();

	std::cout << std::endl << CYAN << "=== Creation of characters ===" << RESET << std::endl;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	ICharacter* nobody = new Character("nobody");

	std::cout << YELLOW << "Equipping the character 'me' with Ice and Cure Materia for slot 0 & 1:" << RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	dynamic_cast<Character*>(me)->displayInventory();

	std::cout << YELLOW << "Equipping the character 'bob' with Ice and Cure Materia for slot 0 to 4:" << RESET << std::endl;
	AMateria* bobtmp;
	bobtmp = src->createMateria("ice");
	bob->equip(bobtmp);

	bobtmp = src->createMateria("cure");
	bob->equip(bobtmp);

	bobtmp = src->createMateria("ice");
	bob->equip(bobtmp);

	bobtmp = src->createMateria("cure");
	bob->equip(bobtmp);
	dynamic_cast<Character*>(bob)->displayInventory();

	dynamic_cast<Character*>(nobody)->displayInventory();

	std::cout << std::endl << GREEN << "Using 'me' Materias on 'bob':" << RESET << std::endl;
	me->use(0, *bob); // Doit afficher : * shoots an ice bolt at bob *
	me->use(1, *bob); // Doit afficher : * heals bob's wounds *
	me->use(2, *bob); // Doit afficher slot vide

	std::cout << std::endl << GREEN << "Using 'bob' Materias on 'me':" << RESET << std::endl;
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);

	nobody->use(0, *me); //doit afficher slot 0 vide

	//dynamic cast : convertit en secu un ptr ou ref d'une classe de base vers une classe dérivée.
	//il check au moment de l'exécution si l'objet pointé est réellement du type vers lequel tu souhaites le convertir.
	//si cast pas possible il retourne null pr eviter erreurs

	std::cout << std::endl << GREEN << "===Dynamic cast & deep copy check====" << RESET << std::endl;

	IMateriaSource* srcM = new MateriaSource();

	if (dynamic_cast<MateriaSource*>(srcM)) //si convert ok, on pt utiliser fonctionnalites de MateriaSource
	{
		std::cout << std::endl << CYAN << "=== Cast and Creation of one character ===" << RESET << std::endl;
		MateriaSource* originalM = dynamic_cast<MateriaSource*>(srcM);
		MateriaSource* copyM = new MateriaSource(*originalM);
		ICharacter* meM = new Character("meM");

		std::cout << std::endl << CYAN << "=== Creation and learn of Materia source ===" << RESET << std::endl;

		AMateria* tmpM;
		originalM->learnMateria(new Ice());
		tmpM = originalM->createMateria("ice");
		meM->equip(tmpM);
		originalM->learnMateria(new Cure());
		tmpM = originalM->createMateria("cure");

		std::cout << YELLOW << "Equipping the character 'meM':" << RESET << std::endl;
		meM->equip(tmpM);
		std::cout << std::endl << GREEN << "Using 'meM' Materias on 'bob':" << RESET << std::endl;
		meM->use(0, *bob);
		meM->use(1, *bob);
		meM->use(2, *bob);
		delete copyM;
		delete meM;
	}
	else{std::cout << "srcM isn't a instance of MateriaSource" << std::endl;}//srcM n'est pas une instance de MateriaSource.
	delete srcM;

	std::cout << std::endl << CYAN << "=== Deep copy test of 'me' ===" << RESET << std::endl;
	Character* meCopy = new Character(*(dynamic_cast<Character*>(me)));

	std::cout << YELLOW << "Inventory of the original character 'me':" << RESET << std::endl;
	dynamic_cast<Character*>(me)->displayInventory();

	std::cout << YELLOW << "Inventory of the copied character 'meCopy':" << RESET << std::endl;
	meCopy->displayInventory();

	std::cout << std::endl << GREEN << "Cleaning up created objects..." << RESET << std::endl;
	delete bob;
	delete me;
	delete meCopy;
	delete src;

	return 0;
}
