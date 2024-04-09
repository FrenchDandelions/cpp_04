#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
    this->_brain = new Brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_brain = new Brain;
    this->operator=(copy);
}


Dog& Dog::operator= (const Dog &copy)
{
    std::cout << "Dog copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        delete this->_brain;
        this->_brain = new Brain(*(copy._brain));
    }
    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << getType() << " makes Random dog noises" << std::endl;
}

Brain* Dog::getBrain(void)
{
    return(this->_brain);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain;
}
