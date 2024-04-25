#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public virtual Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &copy);
        Cat& operator= (const Cat &copy);
        ~Cat();

        void makeSound(void) const;
        Brain* getBrain(void);
};

#endif