#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

Cat& Cat::operator= (const Cat &copy)
{
    std::cout << "Cat copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        this->type = copy.type;
    }
    return(*this);
}

void Cat::makeSound(void) const
{
    std::cout << getType() << " makes Random cat noises" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}
