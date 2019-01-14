/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:29:02 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/14 13:29:04 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		four_connections(char *str)
/* Prends chacun des 4 '#' un a un et verifie qu'ils ont une
 * connection avec au moins un autre '#'
 */
{
	char	*chr;
	char	surrounding_chars[5];
	int		connect;

	chr = str;
	surrounding_chars[4] = '\0';
	connect = 0;
	while ((chr = ft_strchr(chr, '#')))
	{
		surrounding_chars[0] = (chr == str) ? 'e' : *(chr - 1);		/*gauche*/
		surrounding_chars[1] = (chr < (str + 5)) ? 'e' : *(chr - 5);/*haut*/
		surrounding_chars[2] = *(chr + 1);							/*droite*/
		surrounding_chars[3] = (chr >= (str + 15)) ? 'e' : *(chr + 5);/*bas*/
		if (ft_strchr(surrounding_chars, '#'))
			 connect++;
		chr++;
	}
	return (connect == 4);
}

int		is_valid(char *str)
/*  Verifie si le tetromino envoye contient :
 *  4 '#', 4 lignes de 4 caracteres, uniquement des '#' et des '.'
 */
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a == 0 || (a < 20 && str[a++] == '\n'))
		while (a % 5 < 4 && (str[a] == '#' || str[a] == '.'))
			if (str[a++] == '#')
				b++;
	return (str[a] == '\n' && b == 4 && a == 20 && four_connections(str));
}

