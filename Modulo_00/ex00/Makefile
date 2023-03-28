NAME			= megaphone

SOURCE			= megaphone.cpp

OBJECT			= $(SOURCE:.cpp=.o)

COMPILE			= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
ORANGE 			= 	\033[38;5;202m

all:	$(NAME)

%.o:	%.cpp
		@$(COMPILE) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJECT)
			@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)
			@echo "$(GREEN)Executable OK!	$(RESET)"

		
clean:
			@rm -f $(OBJECT)
			@echo "$(ORANGE)Object files removed" $(RESET)"

fclean:		
			@rm -f $(NAME) $(OBJECT)
			@echo "$(ORANGE)Executable removed $(RESET)"

re:			fclean all

.PHONY:		all clean fclean re