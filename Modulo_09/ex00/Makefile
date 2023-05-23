SOURCE_FILES	=	main.cpp BitcoinExchange.cpp

SOURCE_DIR		=	./

OBJ_DIR			=	objects

HEADERS			=	BitcoinExchange.hpp

SOURCES			=	$(addprefix $(SOURCE_DIR)/, $(SOURCE_FILES))

OBJECTS			=	$(SOURCES:$(SOURCE_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME			=	btc

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

RM				=	rm -rf

$(OBJ_DIR)/%.o:		$(SOURCE_DIR)/%.cpp $(HEADERS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
RED				=	\033[1;31m

$(NAME):	$(OBJ_DIR) $(OBJECTS) $(HEADERS)
			$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
			@echo "$(GREEN)Executable OK!	$(RESET)"

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

run:
			./$(NAME)

runv:		all
			valgrind -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./btc

clean:
			@$(RM) $(OBJ_DIR)
			@echo "$(RED)Object files removed $(RESET)"

fclean:		clean
			@$(RM) $(NAME)	
			@echo "$(RED)Executable removed $(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
