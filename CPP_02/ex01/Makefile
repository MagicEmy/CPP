# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 13:55:16 by emlicame          #+#    #+#              #
#    Updated: 2023/06/28 11:37:14 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

INC = Fixed.hpp

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:%.cpp=obj/%.o)
DEP_DIR = dep
DEP = $(SRC:%.cpp=$(DEP_DIR)/%.d)

CC = c++
FLAGS = -Wall -Werror -Wextra
FLAGS += -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

obj/%.o: %.cpp | obj $(DEP_DIR)
	@$(CC) $(FLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

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