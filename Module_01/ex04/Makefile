# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:18:36 by emlicame          #+#    #+#              #
#    Updated: 2023/05/19 19:42:02 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Sed

SRC = main.cpp 

OBJ = $(SRC:%.cpp=obj/%.o)

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
obj/%.o: %.cpp
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re