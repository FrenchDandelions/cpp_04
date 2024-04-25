#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Random AAnimal")
{
    std::cout << "Default AAnimal constuctor called" << std::endl;
}

AAnimal::AAnimal(const std::string &name)
{
    std::cout << "AAnimal constuctor called" << std::endl;
    this->type = name;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

AAnimal& AAnimal::operator= (const AAnimal &copy)
{
    std::cout << "AAnimal copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        this->type = copy.type;
    }
    return(*this);
}

std::string AAnimal::getType(void) const
{
    return(this->type);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}
