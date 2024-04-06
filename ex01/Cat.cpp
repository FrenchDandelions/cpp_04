#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
    this->_brain = new Brain;
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
        delete this->_brain;
        this->type = copy.type;
        this->_brain = new Brain(copy);
    }
    return(*this);
}

void Cat::makeSound(void) const
{
    std::cout << getType() << " makes Random cat noises" << std::endl;
}

Brain* Cat::getBrain(void)
{
    return(this->_brain);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->_brain;
}
