#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    {
        std::cout << std::endl << "****************Test1****************" << std::endl << std::endl;
        // const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        // std::cout << "meta is " << meta->getType() << " " << std::endl;
        std::cout << "j is " << j->getType() << " " << std::endl;
        std::cout << "i is " << i->getType() << " " << std::endl;

        i->makeSound();
        j->makeSound();
        // meta->makeSound();

        // delete meta;
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
        if(!brain2.getSize())
        std::cout << "Brain 2 has no ideas" << std::endl;
        else
        {
            for(int i= 0; i < brain2.getSize(); i++)
            {
                std::cout << "Idea brain2 number " << i + 1 << " is " << brain2.getIdeas()[i] << std::endl; 
            }
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
        std::cout << "Now let's try to break brain1" << std::endl;
        for(int i = 0; i < 104; i++)
        {
            std::string idea = "Breaking it...";
            std::cout << idea << std::endl;
            brain1.newIdea(idea);
        }
    }
    {
        std::cout << std::endl << "****************Test4****************" << std::endl << std::endl;
        std::cout << std::endl << "***Testing new dog and cat classes***" << std::endl << std::endl;
        Dog *dog1 = new Dog;
        Cat *cat1 = new Cat;

        std::cout << "dog1 is " << dog1->getType() << " " << std::endl;
        std::cout << "cat1 is " << cat1->getType() << " " << std::endl;

        std::cout << "dog1 has " << dog1->getBrain()->getSize() << " ideas" << std::endl;
        std::cout << "cat1 has " << cat1->getSize() << " ideas" << std::endl;
        std::cout << "Now let's add some ideas inside dog1's brain!" << std::endl;
        for(int i = 0; i < 6; i++)
        {
            std::string idea = "I'm a dog";
            std::cout << "Adding new idea..." << std::endl;
            dog1->getBrain()->newIdea(idea);
        }
        std::cout << "Here are dog1's ideas :" << std::endl;
        for(int i = 0; i < dog1->getBrain()->getSize(); i++)
        {
            std::cout << "Idea dog1 number " << i + 1 << " is: " << dog1->getBrain()->getIdeas()[i] << std::endl; 
        }
        std::cout << "Now let's test what would happen if we create a new dog based on dog1's brain!" << std::endl;
        Dog *dog2 = new Dog(*dog1);
        std::cout << "Here are dog1's ideas, what a smart dog!" << std::endl;
        for(int i = 0; i < dog2->getBrain()->getSize(); i++)
        {
            std::cout << "Idea dog2 number " << i + 1 << " is: " << dog2->getBrain()->getIdeas()[i] << std::endl; 
        }
        std::cout << "Now let's put more ideas inside dog2's brain!" << std::endl; 
        for(int i = 0; i < 6; i++)
        {
            std::string idea = "I'm a dog";
            std::cout << "Adding new idea..." << std::endl;
            dog2->getBrain()->newIdea(idea);
        }
        std::cout << "Here are dog1's ideas which should have remained unchanged" << std::endl;
        for(int i = 0; i < dog1->getBrain()->getSize(); i++)
        {
            std::cout << "Idea dog1 number " << i + 1 << " is: " << dog1->getBrain()->getIdeas()[i] << std::endl; 
        }
        std::cout << "Here are dog2's ideas which should have changed" << std::endl;
        for(int i = 0; i < dog2->getBrain()->getSize(); i++)
        {
            std::cout << "Idea dog2 number " << i + 1 << " is: " << dog2->getBrain()->getIdeas()[i] << std::endl; 
        }
        std::cout << "Cat1 seems to have a new idea, let's check it out!" << std::endl;
        std::string newidea = "I'll rule the world!";
        cat1->getBrain()->newIdea(newidea);
        std::cout << "Idea cat1: " << cat1->getBrain()->getIdeas()[0] << std::endl;
        std::cout << "Let's be careful around the cat..." << std::endl;
        delete dog1;
        delete cat1;
        delete dog2;
    }
    {
        std::cout << std::endl << "****************Test5****************" << std::endl << std::endl;
        std::cout << std::endl << "*********Test array creation*********" << std::endl << std::endl;
        const int size = 7;
        std::cout << "The zoo is coming" << std::endl;
        Animal *zoo[size];
        for (int i = 0; i <= size; i++)
        {
            (i % 2 == 0) ? zoo[i] = new Dog() : zoo[i] = new Cat();
        }
        std::cout << std::endl;
        for (int i = 0; i <= size; i++)
        {
            std::cout << "Animal "<< i + 1 << " is a " << zoo[i]->getType() << " " << std::endl;
        }
        std::cout << std::endl;
        for(int i = 0; i <= size; i++)
        {
            zoo[i]->makeSound();
        }
        std::cout << std::endl;
        for(int i = 0; i <= size; i++)
            delete zoo[i];
    }
}
