#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
        int size;
    public:
        Brain();
        Brain(const Brain &copy);
        Brain& operator=(const Brain &copy);
        ~Brain();
        void newIdea(std::string &idea);
        std::string* getIdeas(void);
        int getSize(void);
};

#endif