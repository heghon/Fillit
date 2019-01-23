/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:29:02 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/23 16:18:10 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK
# define CHECK
# include "fillit.h"
# define RESET(x) (x = -1)

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
	if (str[a] == '.' || str[a] == '#')
		while (a == 0 || (a < 20 && str[a++] == '\n'))
			while (a % 5 < 4 && (str[a] == '#' || str[a] == '.'))
				if (str[a++] == '#')
					b++;
	return (!str[a] && b == 4 && a == 20 && four_connections(str));
}

t_tetri	format_tetri(char *str, char id)
{
	char	rtn[6][4];
	int		v[3];
	t_tetri tt;

	v[0] = -1;
	v[2] = 0;
	tt.h = 0;
	tt.l = 0;
	while (++v[0] <= 3 && RESET(v[1]) && (rtn[4][v[0]] = '.'))
		while (++v[1] <= 3 && (rtn[v[0]][v[1]] = str[v[0] * 5 + v[1]]))
			if (rtn[4][v[0]] != '#' && rtn[v[0]][v[1]] == '#' && ++tt.h)
				rtn[4][v[0]] = '#';
	RESET(v[1]);
	while (++v[1] <= 3 && RESET(v[0]) && (rtn[5][v[1]] = '.'))
		while (++v[0] <= 3)
			if (rtn[5][v[1]] != '#' && rtn[v[0]][v[1]] == '#' && ++tt.l)
				rtn[5][v[1]] = '#';
	if (!(tt.str = malloc(tt.h * tt.l)))
		exit(-1);
	RESET(v[0]);
	while (++v[0] <= 3 && (RESET(v[1])))
		while (++v[1] <= 3)
			if (rtn[4][v[0]] == '#' && rtn[5][v[1]] == '#')
				tt.str[v[2]++] = rtn[v[0]][v[1]] == '#' ? id : '.';
	return (tt);
}
#endif
