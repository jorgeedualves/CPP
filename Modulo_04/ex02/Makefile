NAME			=	abstract

SOURCES_FILES	=	AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp 

SOURCES_DIR		=	./

OBJ_DIR			=	objects

HEADERS			=	AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors -g -fsanitize=address

RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.cpp $(HEADERS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADERS)
					$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)
					
clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re