/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:56:39 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/18 15:56:41 by bprunevi         ###   ########.fr       */
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
	while (++i < tt.h && (j = -1))
		while (++j < tt.l)
			if (tt.str[i * tt.l + j] != '.')
			{
				if (square[pos + (i * side) + j] != '.')
					return(NULL);
				else
					square[pos + (i * side) + j] = 'A';
			}
	return (square);
}

#endif
