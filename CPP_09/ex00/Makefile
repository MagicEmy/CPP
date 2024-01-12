NAME 		= btc

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
SRC 		= main.cpp

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

re: fclean all

.PHONY: all clean fclean re