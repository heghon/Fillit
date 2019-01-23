# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 18:53:28 by bmenant           #+#    #+#              #
#    Updated: 2019/01/23 15:59:19 by bprunevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Wextra -Werror
SRC = fillit.c check.c solve.c
SRCO = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@ $(CC) -c $(SRC)
	@ $(CC) -o $(NAME) $(SRCO) libft/libft.a

clean :
	@ /bin/rm -f $(SRCO)

fclean : clean
	@ /bin/rm -f $(NAME)

re : fclean all
