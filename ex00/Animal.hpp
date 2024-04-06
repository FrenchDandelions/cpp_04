#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const std::string &name);
        Animal(const Animal &copy);
        Animal& operator= (const Animal &copy);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType(void) const;
};

#endif