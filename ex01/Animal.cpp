#include "Animal.hpp"

Animal::Animal() : type("Random Animal")
{
    std::cout << "Default Animal constuctor called" << std::endl;
}

Animal::Animal(const std::string &name)
{
    std::cout << "Animal constuctor called" << std::endl;
    this->type = name;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

Animal& Animal::operator= (const Animal &copy)
{
    std::cout << "Animal copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        this->type = copy.type;
    }
    return(*this);
}

void Animal::makeSound(void) const
{
    std::cout << getType() << " makes Random animal noises" << std::endl;
}

std::string Animal::getType(void) const
{
    return(this->type);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}
