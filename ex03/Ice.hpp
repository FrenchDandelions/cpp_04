#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : virtual public AMateria
{
    public:
        Ice();
        Ice(const Ice &copy);
        Ice& operator= (const Ice &copy);
        ~Ice();
        AMateria *clone() const;
};

#endif
