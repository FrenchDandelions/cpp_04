#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const std::string &name);
        AAnimal(const AAnimal &copy);
        AAnimal& operator= (const AAnimal &copy);
        virtual ~AAnimal();
        virtual void makeSound() const = 0;
        std::string getType(void) const;
};

#endif