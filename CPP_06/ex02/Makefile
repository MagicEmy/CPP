# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emlicame <emlicame@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/21 17:22:10 by emlicame      #+#    #+#                  #
#    Updated: 2023/11/22 12:46:52 by emlicame      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= RealType

INCLUDE_DIR = include

SRC_DIR		= src
DEP_DIR		= dep
OBJ_DIR		= obj
DEP 		= $(SRC:%.cpp=$(DEP_DIR)/%.d)

CC 			= c++
FLAGS 		= -Wall -Werror -Wextra
# FLAGS 		+= -std=c++98
# FLAGS 	+= -fsanitize=address

INC 		= -I $(INCLUDE_DIR)
OBJ 		= $(SRC:%.cpp=obj/%.o)
SRC			= 	Base.cpp	\
				main.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(INC) $(FLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
