#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
    this->_brain = new (std::nothrow) Brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_brain = new (std::nothrow) Brain;
    this->operator=(copy);
}


Dog& Dog::operator= (const Dog &copy)
{
    std::cout << "Dog copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        if(this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*(copy._brain));
    }
    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << getType() << " makes random dog noises" << std::endl;
}

Brain* Dog::getBrain(void)
{
    return(this->_brain);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    if(this->_brain)
        delete this->_brain;
}
