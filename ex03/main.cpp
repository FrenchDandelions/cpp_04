#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Colors.hpp"

int main()
{
    {
		std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
		std::cout <<"BASIC TEST:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    std::cout << std::endl;
	    std::cout << GREEN "CONSTRUCTORS:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    IMateriaSource* src = new MateriaSource();
	    src->learnMateria(new Ice());
	    src->learnMateria(new Cure());
	    ICharacter* me = new Character("me");
	    std::cout << std::endl; 

	    std::cout << GREEN "CREATE MATERIA:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    AMateria	*tmp;
	    AMateria	*tmp1;
	    AMateria	*tmp2;
	    AMateria	*tmp3;  

	    tmp = src->createMateria("ice");
	    me->equip(tmp);
	    tmp1 = src->createMateria("cure");
	    me->equip(tmp1);
	    tmp = src->createMateria("fire"); // null
	    me->equip(tmp);
	    std::cout << std::endl; 

	    std::cout << GREEN "USE ON A NEW CHARACTER:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    ICharacter* bob = new Character("bob");
	    me->use(0, *bob);
	    me->use(1, *bob);
	    std::cout << std::endl;
	    me->use(2, *bob); // Use an empty / non existing slot in inventory
	    me->use(-4, *bob);
	    me->use(18, *bob);
	    std::cout << std::endl; 

	    // Deep copy character
	    std::cout << GREEN "DEEP COPY CHARACTER:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    Character	*charles = new Character("Charles");
	    tmp2 = src->createMateria("cure");
	    charles->equip(tmp2);
	    tmp3 = src->createMateria("ice");
	    charles->equip(tmp3);
	    tmp = src->createMateria("earth");
	    charles->equip(tmp);
	    Character	*charles_copy = new Character(*charles);
	    std::cout << std::endl; 

	    // Deep copy vs its source character
	    std::cout << GREEN "DEEP COPY VS SOURCE:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    charles->unequip(0); // this shows that they have different materia pointers equipped
	    tmp = src->createMateria("cure");
	    charles_copy->equip(tmp);
	    tmp = src->createMateria("ice");
	    charles_copy->equip(tmp);
	    std::cout << std::endl; 

	    charles->use(0, *bob);
	    charles->use(1, *bob);
	    charles->use(2, *bob);
	    charles->use(3, *bob);
	    std::cout << std::endl;
	    charles_copy->use(0, *bob);
	    charles_copy->use(1, *bob);
	    charles_copy->use(2, *bob);
	    charles_copy->use(3, *bob);
	    std::cout << std::endl; 

	    std::cout << GREEN "UNEQUIP:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    me->unequip(-1); // unequip an empty / non existing slot in inventory
	    me->unequip(18);
	    me->unequip(3);
	    std::cout << std::endl;
	    me->use(1, *charles);
	    me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
	    me->use(1, *charles);
	    std::cout << std::endl; 

	    std::cout << GREEN "DESTRUCTORS:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    delete bob;
	    delete me;
	    delete src;
	    delete charles;
	    delete charles_copy;
	    delete tmp1;
	    delete tmp2;
	    std::cout << std::endl;
    }
    {
	    std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
		std::cout <<"TEST OVERLOADING INVENTORIES:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        MateriaSource *src = new MateriaSource(); //creating new materiasource to store materias
	
		std::cout << std::endl << GREEN "LEARNING NEW MATERIAS:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
	    src->learnMateria(new Ice());
	    src->learnMateria(new Cure());
        src->learnMateria(new Ice());

		std::cout << std::endl << GREEN "TESTING COPY OPERATOR:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        MateriaSource *src2 = new MateriaSource(*src);
		std::cout << std::endl << GREEN "OVERLOADING MATERIASOURCE:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        src2->learnMateria(new Ice());
		AMateria *ice = new Ice();
        src2->learnMateria(ice);//this one cannot be added
        src->learnMateria(new Ice());//shows that they are different ptrs
	
        std::cout << std::endl << GREEN "CREATING NEW CHARACTER TO OVERLOAD:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
		Character *me = new Character("Robert");
	
		std::cout << std::endl << GREEN "CREATING NEW MATERIAS TO PUT INSIDE THE INVENTORY:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        AMateria *tmp = src2->createMateria("cure");
        AMateria *tmp1 = src2->createMateria("cure");
        AMateria *tmp2 = src2->createMateria("ice");
        AMateria *tmp3 = src2->createMateria("ice");
        AMateria *tmp4 = src2->createMateria("ice");
	
        me->equip(tmp);
        me->equip(tmp1);
        me->equip(tmp2);
        me->equip(tmp3);
        me->equip(tmp4);//this one cannot be equipped

		std::cout << std::endl << GREEN "DESTRUCTORS:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        delete src;
        delete src2;
        delete me;
		delete tmp4;
		delete ice;
    }
}