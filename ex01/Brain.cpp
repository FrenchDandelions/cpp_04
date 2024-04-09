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
    std::cout << "Brain copy assignement operator called" << std::endl;
    if(this != &copy)
    {
        this->size = copy.size;
        for(int i = 0; i < 100 ; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return(*this);
}

void Brain::setIdeas(const std::string *ideas){
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = ideas[i];
    }
}

void Brain::setSize(int newSize){
    if(newSize >= 0)
        this->size = newSize;
    else
        std::cout << "You can't have a negative number of ideas..." << std::endl;
}

void Brain::newIdea(std::string &idea){
    if(this->size < 100)
    {
        this->ideas[this->size] = idea;
        ++this->size;
    }
    else
    {
        std::cout << "Stop trying to break my brain! :(" << std::endl;
    }
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
