#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) : type(name)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->operator=(copy);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        this->type = copy.type;
    }
    return(*this);
}

void WrongAnimal::makeSound(void) const{
    std::cout << getType() << " makes WrongAnimal noises" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return(this->type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}