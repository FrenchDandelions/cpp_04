#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    this->_num_materia = 0;
    this->_materias[0] = NULL;
    this->_materias[1] = NULL;
    this->_materias[2] = NULL;
    this->_materias[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    this->operator=(copy);
}

int MateriaSource::getNumMateria(void) const
{
    return(this->_num_materia);
}

std::string MateriaSource::getType(int index) const
{
    if(index > 3 || index < 0)
    {
        std::cout << "Error, wrong index" << std::endl;
        return("None");
    }
    return(this->_materias[index]->getType());
}


MateriaSource& MateriaSource::operator= (const MateriaSource &copy)
{
    std::cout << "MateriaSource copy operator called" << std::endl;
    if(this!= &copy)
    {
        this->_num_materia = copy.getNumMateria();
        for(int i = 0; i < this->_num_materia; i++)
        {
            this->_materias[i] = copy.createMateria(copy.getType(i));
        }
        for(int i = 0; i + this->_num_materia < 4; i++)
        {
            this->_materias[i + this->_num_materia] = NULL;
        }
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource is being destroyed" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(this->_materias[i] != NULL)
            delete this->_materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* newMateria)
{
    if(this->_num_materia < 4)
    {
        this->_materias[this->_num_materia] = newMateria;
        this->_num_materia++;
    }
    else
    {
        std::cout << "Couldn't learn the new materia because the MateriaSource was full" << std::endl;
        delete newMateria;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) const
{
    if(type == "ice")
        return (new (std::nothrow) Ice());
    else if (type == "cure")
        return (new (std::nothrow) Cure());
    else
        std::cout << "Materia " << type << " doesn't exist" << std::endl;
    return (0);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if(type == "ice")
        return (new (std::nothrow) Ice());
    else if (type == "cure")
        return (new (std::nothrow) Cure());
    else
        std::cout << "Materia " << type << " doesn't exist" << std::endl;
    return (0);
}
