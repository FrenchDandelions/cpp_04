#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const std::string &name);
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal& operator= (const WrongAnimal &copy);
        virtual ~WrongAnimal();
        virtual void makeSound(void) const;
        std::string getType(void) const;

};

#endif