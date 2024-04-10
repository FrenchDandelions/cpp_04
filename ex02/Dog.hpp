#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public virtual AAnimal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog& operator= (const Dog &copy);
        ~Dog();

        void makeSound(void) const;
        Brain* getBrain(void);
};

#endif