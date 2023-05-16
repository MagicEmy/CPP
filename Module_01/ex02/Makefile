# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 18:43:52 by emlicame          #+#    #+#              #
#    Updated: 2023/05/16 20:12:11 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ThisIsBrain

SRC = main.cpp

OBJ = $(SRC:%.cpp=obj/%.o)

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

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