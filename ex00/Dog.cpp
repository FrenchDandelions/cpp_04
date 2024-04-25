#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

Dog& Dog::operator= (const Dog &copy)
{
    std::cout << "Dog copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        this->type = copy.type;
    }
    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << getType() << " makes random dog noises" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}
