# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 13:14:48 by emlicame          #+#    #+#              #
#    Updated: 2023/06/12 14:12:37 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

INC = Fixed.hpp

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:%.cpp=obj/%.o)

CC = c++
FLAGS = -Wall -Werror -Wextra
FLAGS += -std=c++98

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

re: fclean all

.PHONY: all clean fclean re