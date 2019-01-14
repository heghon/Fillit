# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 18:53:28 by bmenant           #+#    #+#              #
#    Updated: 2019/01/14 14:06:19 by bprunevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@ $(CC) fillit.c -o fillit.o libft/libft.a

clean :
	@ /bin/rm -f fillit.o

fclean : clean
	@ /bin/rm -f $(NAME)

re : fclean all
