# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 18:53:28 by bmenant           #+#    #+#              #
#    Updated: 2019/01/18 12:37:04 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Wextra -Werror
SRC = fillit.c 
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
