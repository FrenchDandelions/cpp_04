#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Materia cure created!" << std::endl;
}

/*returns NULL if the new fails*/
AMateria * Cure::clone() const
{
    std::cout << "Cure cloned !" << std::endl;
    return(new (std::nothrow) Cure());
}

Cure::Cure(const Cure &copy)
{
    this->Cure::operator=(copy);
}

Cure& Cure::operator=(const Cure &copy)
{
    if(this != &copy){
        this->AMateria::operator=(copy);
    }
    return(*this);
}

Cure::~Cure()
{
    std::cout << "Materia cure destroyed" << std::endl;
}
