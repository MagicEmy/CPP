NAME 		= RPN

INCLUDE_DIR = include

SRC_DIR		= src
OBJ_DIR		= obj
DEP_DIR		= dep
DEP 		= $(SRC:%.cpp=$(DEP_DIR)/%.d)

CC 			= c++
FLAGS 		= -Wall -Werror -Wextra
# FLAGS 		+= -std=c++98
# FLAGS 		+= -fsanitize=address

INC 		= -I $(INCLUDE_DIR)
OBJ 		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
SRC 		= main.cpp Rpn.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(INC) $(FLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEP_DIR)

fclean: clean
	@rm -f $(NAME)

run: all
	@clear
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +" 
	@./$(NAME)	"7 7 * 7 -" 
	@./$(NAME)	"1 2 * 2 / 2 * 2 4 - +" 
	@./$(NAME)	"(1 + 1)" 
	@./$(NAME)	"1 0 /" 
	@./$(NAME)	"1 2 / a" 
	@./$(NAME)	asdasdasd 
	@./$(NAME)	"3" 
	@./$(NAME)	"3 3" 
	@./$(NAME)	" " 
	@./$(NAME)	" + 3 4" 
	@./$(NAME)	" + - " 
	@./$(NAME)	"3 4 5 7 9 2 - + + + +"
		
re: fclean all

.PHONY: all clean fclean re