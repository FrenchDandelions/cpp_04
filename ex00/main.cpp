#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        std::cout << std::endl << "****************Test1****************" << std::endl << std::endl;
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
        delete j;
        delete i;
    }
    {
        std::cout << std::endl << "****************Test2****************" << std::endl << std::endl;
        const WrongAnimal* base = new WrongAnimal();
        const WrongAnimal* rando = new WrongCat();

        std::cout << "base is " << base->getType() << " " << std::endl;
        std::cout << "rando is " << rando->getType() << " " << std::endl;

        rando->makeSound();
        base->makeSound();

        delete base;
        delete rando;
    }

}
