#include "AMateria.hpp"

AMateria::AMateria() : type("none")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "New Materia created!" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const{
    return(this->type);
}

void AMateria::use(ICharacter& target)
{
    if(this->type == "cure")
    {
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
    }
    else if(this->type == "ice")
    {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    }
    else
        std::cout << "Couldn't use " << this->type << " materia" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : type(copy.getType())
{
}

AMateria& AMateria::operator=(const AMateria &copy)
{
    if(this != &copy){
        (const_cast<std::string&>(this->type)) = copy.getType();
    }
    return(*this);
}
