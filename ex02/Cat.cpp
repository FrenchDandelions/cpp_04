#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
    this->_brain = new (std::nothrow) Brain;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_brain = new (std::nothrow) Brain;
    this->operator=(copy);
}


Cat& Cat::operator= (const Cat &copy)
{
    std::cout << "Cat copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        if(this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(copy._brain));
    }
    return(*this);
}

void Cat::makeSound(void) const
{
    std::cout << getType() << " makes random cat noises" << std::endl;
}

Brain* Cat::getBrain(void)
{
    return(this->_brain);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    if(this->_brain)
        delete this->_brain;
}
