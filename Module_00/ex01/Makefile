# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: emanuela <emanuela@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/01 17:27:49 by emanuela      #+#    #+#                  #
#    Updated: 2023/05/01 17:29:36 by emanuela      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SRC = PhoneBook.cpp
OBJ = $(SRC:%.cpp=obj/%.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

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