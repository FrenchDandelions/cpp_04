#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Materia ice created!" << std::endl;
}

AMateria * Ice::clone() const
{
    return(new (std::nothrow) Ice());
}

Ice::Ice(const Ice &copy)
{
    this->Ice::operator=(copy);
}

Ice& Ice::operator=(const Ice &copy)
{
    if(this != &copy){
        this->AMateria::operator=(copy);
    }
    return(*this);
}

Ice::~Ice()
{
    std::cout << "Materia ice destroyed" << std::endl;
}
