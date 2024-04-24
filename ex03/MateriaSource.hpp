#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
    private:
        int _num_materia;
        AMateria *_materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource& operator= (const MateriaSource &copy);
        ~MateriaSource();
        void learnMateria(AMateria* newMateria);
        AMateria* createMateria(std::string const & type);
        AMateria* createMateria(std::string const & type) const;
        int getNumMateria(void) const;
        std::string getType(int index) const;
};

#endif
