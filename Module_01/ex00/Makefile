# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 18:32:51 by emlicame          #+#    #+#              #
#    Updated: 2023/05/16 15:31:16 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brainz

INC =  Zombie.hpp

SRC = 	main.cpp		\
		Zombie.cpp		\
		newZombie.cpp 	\
		randomChump.cpp

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

re: fclean all

.PHONY: all clean fclean re
