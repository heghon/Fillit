/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:28:30 by bmenant           #+#    #+#             */
/*   Updated: 2019/01/17 17:43:45 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verification(t_tetri *tetri, int side, char *final_str, int s)
{
	int		i;

	i = 0;
	if (s == side * side)
		return (-1);
	while (tetri->str)
	{
		if (final_str[s] != '.' && tetri->str[i++] != '.')
			return (0);
		if (s == ((s % 4) + tetri->l))
			s += side;
		else
			s++;
	}
	return (1);
}

void	placement(t_tetri *tetri, int side, char *final_str, int s)
{
	int		i;

	i = 0;
	while (tetri->str)
	{
		final_str[s] = tetri->str[i++];
		if (s == ((s % 4) + tetri->l))
			s += (side - tetri->l);
		else
			s++;
	}
}

char	*resolve(t_tetri *tetri, int side, int start)
	/* on doit commencer start a 0 et side a 2 */
{
	char		*final_str;
//	int			s;
	int			ret;
	t_tetri		*backup;

	if (start = side * side)
		return (resolve(tetri, ++side, 0));
	final_str = ft_strnew((size_t)(side * side));
	final_str = ft_memset(final_str, '.', (side * side));
	backup = tetri;
//	start = 0;
	while (tetri->str)
	{
		if (ret = verification(tetri, side, final_str, start) == 0)
			start++;
		else if (ret == -1)
		{
			free(final_str);
			return (resolve(backup, side, ++start));
		}
		else
		{
			placement(tetri, side, final_str, start);
			tetri = tetri->next;
		}
	}
	return (final_str);
}
