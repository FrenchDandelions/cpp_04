#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public virtual Animal
{
    private:
        /* data */
    public:
        Dog();
        Dog(const Dog &copy);
        Dog& operator= (const Dog &copy);
        ~Dog();

        void makeSound(void) const;
};

#endif