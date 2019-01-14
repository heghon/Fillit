/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:28:30 by bmenant           #+#    #+#             */
/*   Updated: 2019/01/14 18:41:02 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* side = cote du carre final */

int		placement(t_tetri tetri, int side, char *final_str, static int start)
{
	int			j;

	if (start == size * size + 1)
		return (-1);
	if ((((start % 4) + tetri->width) / 4) > 0 || final_str != 46)
		return (0);
	if ((((start / 4) + tetri->height) / 4) > 0 || final_str != 46)
		return (0);
	j = 0;
	while (j != 4)
	{
		final_str[start] = tetri->str[j];
		else
		if (j == ((start % 4) + tetri->width))
			j += side - tetri->width;
		else
			j++;
		start++;
	}
	start = tetri->width;
	return (1);
}

char	*resolve(t_list list,int  side)
{
	char	*final_str;
	int		i;
	int		j;
	static int	start = 0;

	if (!(final_str = (char *)malloc(sizeof(char) * (side * side + 1))))
		return (NULL);
	final_str = ft_memset(final_str, 46, (side * side));
	final_str[size * size + 1] = '\0';
	i = 0;
	while (list)
	{
		while (placement == 1)
	}
}
