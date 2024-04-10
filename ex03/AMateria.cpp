#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}
