# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAkefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 14:13:20 by emlicame          #+#    #+#              #
#    Updated: 2023/06/12 14:13:58 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

INC = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

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
