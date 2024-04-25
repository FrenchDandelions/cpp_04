#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public virtual AAnimal
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