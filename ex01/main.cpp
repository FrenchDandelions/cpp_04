#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

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
    {
        std::cout << std::endl << "****************Test3****************" << std::endl << std::endl;
        std::cout << std::endl << "*********Testing brain class*********" << std::endl << std::endl;
        Brain brain1;

        for(int i = 0; i < 6; i++)
        {
            std::string str = "Coucou";
            brain1.newIdea(str);
        }
        for(int i= 0; i < brain1.getSize(); i++)
        {
            std::cout << "Idea brain1 number " << i + 1 << " is " << brain1.getIdeas()[i] << std::endl; 
        }
        Brain brain2;
        for(int i= 0; i < brain2.getSize(); i++)
        {
            std::cout << "Idea brain2 number " << i + 1 << " is " << brain2.getIdeas()[i] << std::endl; 
        }
        brain2 = brain1;
        for(int i= 0; i < brain2.getSize(); i++)
        {
            std::cout << "Idea brain2 number " << i + 1 << " is " << brain2.getIdeas()[i] << std::endl; 
        }
        for(int i = 0; i < 6; i++)
        {
            std::string str = "Coucou";
            brain1.newIdea(str);
        }
        for(int i= 0; i < brain1.getSize(); i++)
        {
            std::cout << "Idea brain1 number " << i + 1 << " is " << brain1.getIdeas()[i] << std::endl; 
        }
        for(int i= 0; i < brain2.getSize(); i++)
        {
            std::cout << "Idea brain2 number " << i + 1 << " is " << brain2.getIdeas()[i] << std::endl; 
        }
    }
    {
        std::cout << std::endl << "****************Test4****************" << std::endl << std::endl;

        Dog *dog1 = new Dog;
        Cat *cat1 = new Cat;

        std::cout << "dog1 is " << dog1->getType() << " " << std::endl;
        std::cout << "cat1 is " << cat1->getType() << " " << std::endl;

        std::cout << "dog1 has " << dog1->getSize() << " ideas" << std::endl;
        std::cout << "cat1 has " << cat1->getSize() << " ideas" << std::endl;

        for(int i = 0; i < 6; i++)
        {
            std::string idea = "I'm a dog";
            dog1->newIdea(idea);
        }
        for(int i = 0; i < dog1->getSize(); i++)
        {
            std::cout << "Idea dog1 number " << i + 1 << " is " << dog1->getIdeas()[i] << std::endl; 
        }
        Dog *dog2 = new Dog;
        dog2 = dog1;
        for(int i = 0; i < dog2->getSize(); i++)
        {
            std::cout << "Idea dog2 number " << i + 1 << " is " << dog2->getIdeas()[i] << std::endl; 
        }
        std::cout << dog2->getSize() << " is the size" << std::endl;
        for(int i = 0; i < 6; i++)
        {
            std::string idea = "I'm a dog";
            dog2->newIdea(idea);
        }
        for(int i = 0; i < dog2->getSize(); i++)
        {
            std::cout << "Idea dog2 number " << i + 1 << " is " << dog2->getIdeas()[i] << std::endl; 
        }
        delete dog1;
        delete cat1;
        delete dog2;
    }

}
