/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:28:30 by bmenant           #+#    #+#             */
/*   Updated: 2019/01/17 15:15:10 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_C
# define RESOLVE_C
# include "fillit.h"

int		placement(t_tetri tetri, int side, char *final_str, int s)
{
	t_tetri	backup;
	int		a;

	backup = tetri;
	a = s;
	if (s == side * side)
		return (-1);
	if ((((s % 4) + tetri->l) / 4) > 0 || (((s / 4) + tetri->h) / 4) > 0)
		return (0);
	while (tetri->str)
	{
		if (final_str[a] != '.' && tetri->*str != '.')
			return (0);
		if (a == ((a % 4) + tetri->l))
			a += (side - tetri->l);
		else
			a++;
		tetri->str++;
	}
	tetri = backup;
	while (tetri->str)
	{
		final_str[s] = tetri->*str;
		if (s == ((s % 4) + tetri->l))
			s += (side - tetri->l);
		else
			s++;
		tetr->str++;
	}
	return (1);
}

char	*resolve(t_tetri tetri, int side)
{
	char		*final_str;
	int			s;
	int			ret;
	t_tetri		*backup;

	final_str = ft_strnew((size_t)(side * side));
	final_str = ft_memset(final_str, '.', (side * side));
	backup = tetri;
	s = 0;
	while (tetri->str)
	{
		ret = placement(tetri, side, final_str, s);
		if (ret == 0)
			s++;
		else if (ret == -1)
		{
			free(final_str);
			return (resolve(backup, ++side));
		}
		else
			tetri = tetri->next;
	}
	return (final_str);
}
#endif
