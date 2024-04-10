#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
    private:
        const std::string &type;
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria &copy);
        AMateria& operator= (const AMateria &copy);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif