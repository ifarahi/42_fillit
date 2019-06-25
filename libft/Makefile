# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afasihi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 12:21:50 by afasihi           #+#    #+#              #
#    Updated: 2018/10/11 12:41:58 by afasihi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror *.c libft.h
	ar rc $(NAME) *.o

clean:
	/bin/rm -f *.o	
	/bin/rm -f *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
