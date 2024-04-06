#include "Brain.hpp"

Brain::Brain()
{
    this->size = 0;
}

Brain::Brain(const Brain &copy)
{
    this->operator=(copy);
}

Brain& Brain::operator=(const Brain &copy)
{
    if(this != &copy)
    {
        this->size = copy.size;
        for(int i = 0; i < this->size ; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return(*this);
}

void Brain::newIdea(std::string &idea){
    this->ideas[this->size] = idea;
    ++this->size;
}

int Brain::getSize(void){
    return(this->size);
}

std::string* Brain::getIdeas(void)
{
    return(this->ideas);
}

Brain::~Brain()
{
}
