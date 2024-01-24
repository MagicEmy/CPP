NAME 		= PmergeMe

INCLUDE_DIR = include

SRC_DIR		= src
OBJ_DIR		= obj
DEP_DIR		= dep
DEP 		= $(SRC:%.cpp=$(DEP_DIR)/%.d)
FILE_NAME	= output.txt

CC 			= c++
FLAGS 		= -Wall -Werror -Wextra
FLAGS 		+= -std=c++11
# FLAGS 		+= -fsanitize=address

INC 		= -I $(INCLUDE_DIR)
OBJ 		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
SRC 		= main.cpp PmergeMe.cpp sortVector.cpp sortDeque.cpp

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
	@rm -rf $(FILE_NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re