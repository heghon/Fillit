/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:29:02 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/23 12:08:48 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK
# define CHECK
# include "fillit.h"

int		four_connections(char *str)
{
	char	*chr;
	char	surrounding_chars[5];
	int		connect;

	chr = str;
	surrounding_chars[4] = '\0';
	connect = 0;
	while ((chr = ft_strchr(chr, '#')))
	{
		if ((chr != str) && (*(chr - 1) == '#'))
			connect++;
		if ((chr >= (str + 5)) && (*(chr - 5) == '#'))
			connect++;
		if (*(chr + 1) == '#')
			connect++;
		if ((chr < (str + 15)) && (*(chr + 5) == '#'))
			connect++;
		chr++;
	}
	return (connect > 5);
}

int		is_valid(char *str)
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

t_tetri	format_tetri(char *str, char id) //
{
	char	rtn[6][4];
	int		i;
	int		j;
	int		x;
	t_tetri tt;

	i = -1;
	x = 0;
	tt.h = 0;
	tt.l = 0;
	while (++i <= 3 && (j = -1) && (rtn[4][i] = '.'))
		while (++j <= 3 && (rtn[i][j] = str[i * 5 + j]))
			if (rtn[4][i] != '#' && rtn[i][j] == '#' && ++tt.h)
				rtn[4][i] = '#';
	j = -1;
	while (++j <= 3 && (i = -1) && (rtn[5][j] = '.'))
		while (++i <= 3)
			if (rtn[5][j] != '#' && rtn[i][j] == '#' && ++tt.l)
				rtn[5][j] = '#';
	if (!(tt.str = malloc(tt.h * tt.l)))
		exit (-1);
	i = -1;
	while (++i <= 3 && (j = -1))
		while (++j <= 3)
			if (rtn[4][i] == '#' && rtn[5][j] == '#')
				tt.str[x++] = rtn[i][j] == '#' ? id : '.';
	tt.next = NULL; //PABO
	tt.square = NULL; //PABO
	return (tt);
}
#endif
