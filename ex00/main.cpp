#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main(void)
{
    {
        std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
		std::cout <<"TEST 1:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "meta is " << meta->getType() << " " << std::endl;
        std::cout << "j is " << j->getType() << " " << std::endl;
        std::cout << "i is " << i->getType() << " " << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        std::cout << std::endl << GREEN "DESTRUCTORS:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        delete j;
        delete i;
    }
    {
        std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
		std::cout <<"TEST 2:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        const WrongAnimal* base = new WrongAnimal();
        const WrongAnimal* rando = new WrongCat();

        std::cout << "base is " << base->getType() << " " << std::endl;
        std::cout << "rando is " << rando->getType() << " " << std::endl;

        rando->makeSound();
        base->makeSound();

        std::cout << std::endl << GREEN "DESTRUCTORS:" << std::endl;
	    std::cout << "---------------------------------------------------" RESET << std::endl;
        delete base;
        delete rando;
    }
}
