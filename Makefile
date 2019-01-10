# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 18:53:28 by bmenant           #+#    #+#              #
#    Updated: 2019/01/07 14:45:02 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@ $(CC) -c fillit.c
	@ $(CC) -o fillit.o libft/libft.a fillit

clean :
	@ /bin/rm -f fillit.o

fclean : clean
	@ /bin/rm -f $(NAME)

re : fclean all
