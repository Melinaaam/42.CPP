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
	std::cout << CYAN << "====== Creation and learn of Materia source ======" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	if (dynamic_cast< MateriaSource*>(src))
		dynamic_cast<MateriaSource*>(src)->displayInventory();

	std::cout << std::endl << CYAN << "====== Creation of characters ======" << RESET << std::endl;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	ICharacter* nobody = new Character("nobody");

	std::cout << "Equipping the character " << YELLOW << me->getName() << RESET << " with Ice and Cure Materia for slot 0 & 1:" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	if (dynamic_cast< Character*>(me))
		dynamic_cast<Character*>(me)->displayInventory();

	std::cout << "Equipping the character " << YELLOW << bob->getName() << RESET << " with Ice and Cure Materia for slot 0 to 4:" << std::endl;
	AMateria* bobtmp;
	bobtmp = src->createMateria("ice");
	bob->equip(bobtmp);

	bobtmp = src->createMateria("cure");
	bob->equip(bobtmp);

	bobtmp = src->createMateria("ice");
	bob->equip(bobtmp);

	bobtmp = src->createMateria("cure");
	bob->equip(bobtmp);
	if (dynamic_cast< Character*>(bob))
		dynamic_cast<Character*>(bob)->displayInventory();

	std::cout << std::endl << "No equiping inventory of : " << YELLOW << nobody->getName() << RESET << std::endl;
	if(dynamic_cast< Character*>(nobody))
		dynamic_cast<Character*>(nobody)->displayInventory();

	std::cout << std::endl << GREEN << "Using " << RESET << YELLOW << me->getName() << RESET << GREEN << " Materias on " << YELLOW << bob->getName() << RESET << std::endl;
	me->use(0, *bob); // Doit afficher : * shoots an ice bolt at bob *
	me->use(1, *bob); // Doit afficher : * heals bob's wounds *
	me->use(2, *bob); // Doit afficher slot vide

	std::cout << std::endl << GREEN << "Using " << RESET << YELLOW << bob->getName() << RESET << GREEN << " Materias on " << YELLOW << me->getName() << RESET << std::endl;

	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);

	std::cout << std::endl << GREEN << "Using " << RESET << YELLOW << nobody->getName() << RESET << GREEN << " Materias on " << YELLOW << me->getName() << RESET << std::endl;

	nobody->use(0, *me); //doit afficher slot 0 vide

	std::cout << std::endl << CYAN << "====== Dynamic cast & deep copy check ======" << RESET << std::endl;

	IMateriaSource* srcM = new MateriaSource();

	if (dynamic_cast<MateriaSource*>(srcM)) //si convert ok, on pt utiliser fonctionnalites de MateriaSource
	{
		MateriaSource* originalM = dynamic_cast<MateriaSource*>(srcM);
		MateriaSource* copyM = new MateriaSource(*originalM);
		ICharacter* meM = new Character("meM");

		AMateria* tmpM;
		originalM->learnMateria(new Ice());
		tmpM = originalM->createMateria("ice");
		meM->equip(tmpM);
		originalM->learnMateria(new Cure());
		tmpM = originalM->createMateria("cure");

		std::cout << std::endl << YELLOW << "Equipping the character 'meM':" << RESET << std::endl;
		meM->equip(tmpM);
		std::cout << std::endl << GREEN << "Using " << RESET << YELLOW << meM->getName() << RESET << GREEN << " Materias on " << YELLOW << bob->getName() << RESET << std::endl;
		meM->use(0, *bob);
		meM->use(1, *bob);
		meM->use(2, *bob);
		delete copyM;
		delete meM;
	}
	else{std::cout << "srcM isn't a instance of MateriaSource" << std::endl;}//srcM n'est pas une instance de MateriaSource.
	delete srcM;

	std::cout << std::endl << CYAN << "=== Deep copy test of 'me' ===" << RESET << std::endl;
	if (dynamic_cast< Character*>(me))
	{
		Character* meCopy = new Character(*(dynamic_cast<Character*>(me)));
		std::cout << YELLOW << "Inventory of the original character 'me':" << RESET << std::endl;
		dynamic_cast<Character*>(me)->displayInventory();

		std::cout << YELLOW << "Inventory of the copied character 'meCopy':" << RESET << std::endl;
		meCopy->displayInventory();
		delete meCopy;
	}
	else{std::cout << "me isn't a instance of Character" << std::endl;}//srcM n'est pas une instance de MateriaSource.
	std::cout << std::endl << GREEN << "Cleaning up created objects..." << RESET << std::endl;
	delete bob;
	delete me;
	delete src;
	delete nobody;

	return 0;
}
