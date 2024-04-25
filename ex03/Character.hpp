#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : virtual public ICharacter
{
    private:
        std::string _name;
        AMateria *inventory[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character &copy);
        Character& operator=(const Character &copy);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int indx);
        void use(int indx, ICharacter& target);
        AMateria *getMateria(int indx) const;
};

#endif