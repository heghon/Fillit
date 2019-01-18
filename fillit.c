/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/18 14:30:22 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_square(char *square, size_t side)
{
	size_t i;
	size_t a;

	i = -1;
	a = 0;
	while (++i < side)
	{
		while (a < side)
			ft_putchar(square[(i * side) + a++]);
		a = 0;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

int		main(int ac, char *argv[1])
/* Teste si tous les tetrominos de 'test_valid' sont valides.
 * Renvoie '-1' dans le cas contraire.
 */
{
	char	tetromino[21];
	t_tetri tetri[26];
	int		i;
	int		fd;

	if (ac == 1)
	{
		write(1, "usage : fillit tetriminos_file\n", 31);
		return (0);
	}
	if (ac > 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	i = -1;
	while (read(fd,tetromino,21) > 0 && (i++ || 1))
	{
		if (!is_valid(tetromino))
			exit(-1);
		tetri[i] = format_tetri(tetromino, 65 + i);
	}
	close(fd);
	return (0);
}
