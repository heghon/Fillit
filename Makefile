# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 18:53:28 by bmenant           #+#    #+#              #
#    Updated: 2019/01/24 11:44:52 by bprunevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Wextra -Werror
SRC = fillit.c check.c solve.c
SRCO = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@ make -C libft
	@ $(CC) -c $(SRC)
	@ $(CC) -o $(NAME) $(SRCO) libft/libft.a

clean :
	@ make -C libft clean
	@ /bin/rm -f $(SRCO)

fclean : clean
	@ make -C libft fclean
	@ /bin/rm -f $(NAME)

re : fclean all
