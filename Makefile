# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 18:53:28 by bmenant           #+#    #+#              #
#    Updated: 2019/01/18 11:58:21 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Wextra -Werror
SRC = check.c \
	  fillit.c \
	  resolve.c
SRCO = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@ $(CC) -c $(SRC)
	@ $(CC) -o $(NAME) $(SRCO) 

clean :
	@ /bin/rm -f $(SRCO)

fclean : clean
	@ /bin/rm -f $(NAME)

re : fclean all
