/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/22 14:33:02 by bprunevi         ###   ########.fr       */
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
	char	*square = ft_strdup(sqr);
	t_tetri *tetri;
	t_tetri *tetri_bckp;
	t_tetri *first;
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
	while (read(fd,tetromino,21) > 0)
	{
		if (!is_valid(tetromino))
			exit(-1);
		if (i == -1)
		{
			tetri_bckp = (t_tetri *)malloc(sizeof(t_tetri));
			*tetri_bckp = format_tetri(tetromino, 65 + ++i);
			first = tetri_bckp;
		}
		else
		{
			tetri = (t_tetri *)malloc(sizeof(t_tetri));
			*tetri = format_tetri(tetromino, 65 + ++i);
			tetri_bckp->next = tetri;
			tetri_bckp = tetri;
		}
	}
	i = 5;
	//ft_strdel(&square);
	//square = ft_strnew(i * i);
	//ft_memset(square, 46, i * i);
	while(!(square = backtracking(square, ++i, 0, *first)))
	{
		ft_strdel(&square);
		ft_strdup(sqr);
	}
	put_square(square, i);
	ft_putstr("\n\n");
	ft_putnbr(i);
	close(fd);
	return (0);
}
