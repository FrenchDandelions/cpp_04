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
        void setIdeas(const std::string *ideas);
        std::string* getIdeas(void);
        void setSize(int newSize);
        int getSize(void);
};

#endif