#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
    this->_brain = new Brain;
}

Dog::Dog(const Dog &copy) : Animal(copy) // Initialize base class
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}


Dog& Dog::operator= (const Dog &copy)
{
    std::cout << "Dog copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        if(this->_brain)
            delete this->_brain;
        this->type = copy.type;
        this->_brain = new Brain;
        for(int i = 0; i < copy.size ; i++)
        {
            this->ideas[i] = copy.ideas[i];
        }
        this->size = copy.size;
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
