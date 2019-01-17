/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:28:30 by bmenant           #+#    #+#             */
/*   Updated: 2019/01/17 12:45:25 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* side = cote du carre final */

void	fill_the_str(char **str, int side)
{
	if (!(str = (static char *)malloc(sizeof(char) * (side * side + 1))))
		return (NULL);
	str = ft_memset(final_str, '.', (side * side));
	str[size * size] = '\0';
}

int		placement(t_tetri tetri, int side, char *final_str, static int start)
{
	int			j;

	if (start == side * side)
		return (-1);
	if ((((start % 4) + tetri->l) / 4) > 0 || final_str[start] != 46)
		return (0);
	if ((((start / 4) + tetri->h) / 4) > 0 || final_str[start] != 46)
		return (0);
	j = 0;
	while (j != 4)
	{
		final_str[start] = tetri->str[j];
		if (start == ((start % 4) + tetri->l))
			start += side - tetri->l;
		else
			start++;
		j++;
	}
	start = tetri->l;
	return (1);
}

char	*resolve(t_tetri tetri, int side)
{
	char		*final_str;
	int			i;
	int			ret;
	static int	start = 0;
	t_tetri		*backup;

	fill_the_str(final_str, side);
	i = 0;
	backup = tetri;
	while (tetri->next)
	{
		ret = placement(tetri, side, final_str, start);
		if (ret == 0)
			start += 1;
		else if (ret == -1)
		{
			start = 0;
			free(final_str);
			tetri = backup;

		}
		else
			tetri = tetri->next;
	}
	return (final_str);
}
