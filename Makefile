# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 20:38:51 by ifarahi           #+#    #+#              #
#    Updated: 2018/12/07 20:39:00 by ifarahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = validation.c  main.c functions1.c functions2.c fillit.c
OBJ = *.o
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)
clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
