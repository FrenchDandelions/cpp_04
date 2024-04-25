#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Materia ice created!" << std::endl;
}

/*returns NULL if the new fails*/
AMateria * Ice::clone() const
{
    std::cout << "Ice cloned !" << std::endl;
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
