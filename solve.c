/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:56:39 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/22 15:38:16 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_C
# define SOLVE_C
# include "fillit.h"

char *tetri_fit(char *square, int side, int pos, t_tetri tt)
{
	int	i;
	int	j;

	i = -1;
	if (side - (pos % side) < tt.l)
		return(NULL);
	if (side - (pos / side) < tt.h)
		return(NULL);
	while (++i < tt.h && (j = -1))
		while (++j < tt.l)
			if (tt.str[i * tt.l + j] != '.')
			{
				if (square[pos + (i * side) + j] != '.')
					return(NULL);
				else
					square[pos + (i * side) + j] = tt.str[i * tt.l + j];
			}
	return (square);
}

char *backtracking(char *square, int side, int pos, t_tetri tt)
{
	char *str;

	//ft_strdel(&tt.square);
	tt.square = ft_strdup(square);
	if (pos == side * side - 3)
		return (NULL);
	if (tetri_fit(square,side,pos,tt))
	{
		if (!tt.next)
			return (square);
		if ((str = backtracking(square, side, 0, *tt.next)))
			return(str);
	}
	return(backtracking(tt.square, side, pos + 1, tt));
}
#endif
