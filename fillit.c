/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/17 12:53:01 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	put_square(char *square, size_t side)
{
	size_t i;

	i = -1;
	while (++i <= side)
	{
		write(1, square + (i * side), side);
		ft_putchar('\n');
	}
}

int		main(int fd, char *argv[1])
/* Teste si tous les tetrominos de 'test_valid' sont valides.
 * Renvoie '-1' dans le cas contraire.
 */
{
	char	tetromino[21];
	t_tetri tetri[26];
	int		i;

	fd = open(argv[1], O_RDONLY);
	i = -1;
	while (read(fd,tetromino,21) > 0 && (i++ || 1))
	{
		if (!is_valid(tetromino))
			exit(-1);
		tetri[i] = format_tetri(tetromino, 65 + i);
	}
	close(fd);
}
