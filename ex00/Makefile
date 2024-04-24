NAME = Polymorphism
VERMILION_RED=\033[1;31m
AZURE_BLUE=\033[1;34m
GOLD_COLOR=\033[38;5;220m
GREEN=\033[0;32m
RESET=\033[0m
SRC_FILES = main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \

INCLUDE = Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp \

OBJECTS = $(SRC_FILES:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)  

$(NAME) : $(OBJECTS) $(INCLUDE) Makefile
	@echo "$(GOLD_COLOR)Compiling Polymorphism...$(RESET)"
	$(CXX) $(CXXFLAGS) -o $(NAME)  $(OBJECTS) 
	@echo "$(GOLD_COLOR)Polymorphism compiled ! :)$(RESET)"

clean:
	@echo "$(AZURE_BLUE)Cleaning in progress...$(RESET)"
	@rm -f $(OBJECTS)
	@echo "$(AZURE_BLUE)Cleanup done ! :)$(RESET)"

fclean: clean
	@echo "$(AZURE_BLUE)Deep cleaning in progress...$(RESET)"
	@rm -f $(NAME)
	@echo "$(AZURE_BLUE)Deep Cleaning over ! :)$(RESET)"	

re: fclean $(NAME)

.PHONY: all clean fclean re