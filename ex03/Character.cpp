#include "Character.hpp"

Character::Character()
{
    this->_name = "Unknown";
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
    std::cout << "New Character created!" << std::endl;
}

Character::Character(std::string name)
{
    this->_name = name;
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
    std::cout << "New Character " << name << " created!" << std::endl;
}

std::string const & Character::getName() const
{
    return(this->_name);
}

void Character::equip(AMateria *m)
{
    int i;
    if(!m)
        std::cout << "This materia doesn't exist" << std::endl;
    for(i = 0; i < 4; i++)
    {
        if(this->inventory[i] == NULL)
            break;
    }
    if(i == 4)
        std::cout << "Couldn't equip new materia, the inventory is full" << std::endl;
    else
        this->inventory[i] = m;
}

/*
you should save the pointers with the getMateria func before using unequip
if the materia you try to unequip if from a copy operator and not from
an external pointer
*/
void Character::unequip(int indx)
{
    if(indx > 3 || indx < 0)
        std::cout << "Couldn't unequip the materia because the index is wrong" << std::endl;
    else if(this->inventory[indx] == NULL)
        std::cout << "Couldn't unequip the materia because there is no materia at this emplacement" << std::endl;
    else
    {
        std::cout << "Character: " << this->getName() << " unequipped the materia " << this->inventory[indx]->getType() << std::endl;
        this->inventory[indx] = NULL;
    }
}

void Character::use(int indx, ICharacter& target)
{
    if(indx > 3 || indx < 0)
        std::cout << "Couldn't use the materia because the index is wrong" << std::endl;
    else if( this->inventory[indx] == NULL)
        std::cout << "Couldn't use the materia because there is no materia at this emplacement" << std::endl;
    else
    {
        this->inventory[indx]->use(target);
    }
}

/*returns NULL if the index is incorrect, else returns the materia pointer*/
AMateria* Character::getMateria(int indx) const
{
    if(indx > 3 || indx < 0 || this->inventory[indx] == NULL)
        return(NULL);
    return(this->inventory[indx]);
}

Character::Character(const Character &copy)
{
    std::cout << "Character copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
    this->operator=(copy);
}

/*
Using the copy operator will delete the already existing materias of the
object where it'll be copied, sobe careful when using it
*/
Character& Character::operator=(const Character &copy)
{
    std::cout << "Character copy operator called" << std::endl;
    if(this != &copy)
    {
        for(int i = 0; i < 4; i++)
            this->inventory[i] != NULL ? delete this->inventory[i] : (void)i;
        this->_name = copy.getName();
        for(int i = 0; i < 4; i++)
        {
            AMateria *p;
            p = copy.getMateria(i);
            p != NULL ? this->inventory[i] = p->clone() : this->inventory[i] = NULL;
        }
    }
    return(*this);
}

Character::~Character()
{
    std::cout << "Character " << this->getName() << " died" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(this->inventory[i] != NULL)
            delete this->inventory[i];
    }
}
