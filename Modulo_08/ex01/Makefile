NAME			=	span

SOURCES_FILES	=	main.cpp Span.cpp

SOURCES_DIR		=	./

OBJ_DIR			=	objects

HEADERS			=	Span.hpp Span.tpp

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -O3 -std=c++98 -g3 -fsanitize=address

RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.cpp $(HEADERS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADERS)
					$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

runv:				all
					valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./span					

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
