NAME			=	form

SOURCES_FILES	=	main.cpp Bureaucrat.cpp Intern.cpp AForm.cpp ShrubberyCreationForm.cpp
SOURCES_FILES	+=	RobotomyRequestForm.cpp PresidentialPardonForm.cpp

SOURCES_DIR		=	./

OBJ_DIR			=	objects

HEADERS			=	Bureaucrat.hpp Intern.hpp AForm.hpp ShrubberyCreationForm.hpp
HEADERS			+=	RobotomyRequestForm.hpp PresidentialPardonForm.hpp

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors -g #-fsanitize=address

RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.cpp $(HEADERS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADERS)
					$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

runv:				all
					valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./form

clean:
					$(RM) $(OBJ_DIR) *_shrubbery

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
