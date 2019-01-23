/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/23 12:38:27 by bprunevi         ###   ########.fr       */
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

void		alloc_tetri(t_tetri *tt, int size)
{
	ft_strdel(&tt->square);
	tt->square = ft_strnew(size);
	if (tt->next)
		alloc_tetri(tt->next, size);
}

void	free_tetri(t_tetri *tt)
{
	ft_strdel(&tt->square);
	ft_strdel(&tt->str);
	if (tt->next)
		free_tetri(tt->next);
	free(tt);
}

t_tetri	*create_tetri(int fd, int i) //
{
	char	tetromino[21];
	t_tetri *tetri;
	t_tetri *tetri_bckp;
	t_tetri *first;

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
	return (first);
}

int		main(int ac, char *argv[1]) //
{
	char	*square;
	char	*final;
	t_tetri *first;
	int		fd;

	if (ac == 1)
		write(1, "usage : fillit tetriminos_file\n", 31);
	if (ac > 2)
		write(1, "error\n", 6);
	if (ac != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	first = create_tetri(fd, -1);

	square = ft_strdup("....");
	alloc_tetri(first, ac * ac);
	while (!(final = backtracking(square, ac++, 0, *first)))
	{
		alloc_tetri(first, ac * ac);
		ft_strdel(&square);
		square = ft_strnew(ac * ac);
		ft_memset(square, '.', ac * ac);
	}
	put_square(final, ac - 1);

	free_tetri(first);
	//ft_strdel(&square);
	ft_strdel(&final);
	close(fd);
	return (0);
}
