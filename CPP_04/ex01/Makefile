# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 14:13:20 by emlicame          #+#    #+#              #
#    Updated: 2023/07/13 11:38:37 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= AnimalsBrain

INCLUDE_DIR = include

SRC_DIR		= src
DEP_DIR		= dep
DEP 		= $(SRC:%.cpp=$(DEP_DIR)/%.d)

CC 			= c++
FLAGS 		= -Wall -Werror -Wextra
FLAGS 		+= -std=c++98

INC 		= -I $(INCLUDE_DIR)
OBJ 		= $(SRC:%.cpp=obj/%.o)
SRC 		= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

obj/%.o: src/%.cpp | obj $(DEP_DIR)
	@$(CC) $(INC) $(FLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

obj $(DEP_DIR):
	@mkdir -p $@

clean:
	@rm -f $(OBJ)
	@rm -rf obj
	@rm -rf $(DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re