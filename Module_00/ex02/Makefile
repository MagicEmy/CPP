# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 15:52:26 by emlicame          #+#    #+#              #
#    Updated: 2023/05/15 17:12:29 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	Account
INC	= 	Account.hpp
		
SRC = 	tests.cpp Account.cpp

OBJ = $(SRC:%.cpp=obj/%.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
obj/%.o: %.cpp $(INC)
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
# 
re: fclean all

.PHONY: all clean fclean re
