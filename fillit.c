/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/23 16:38:13 by bprunevi         ###   ########.fr       */
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
}

void	alloc_tetri(t_tetri *tt, int size)
{
	ft_strdel(&tt->square);
	if (!(tt->square = ft_strnew(size)))
		exit(-1);
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

t_tetri	*list_tetri(int fd, char a)
{
	int		rt;
	char	tetromino[21];
	t_tetri	*tt;

	rt = read(fd, tetromino, 21);
	if (!rt)
		return (NULL);
	if (tetromino[20] == '\n' || rt == 20)
		tetromino[20] = '\0';
	if (!is_valid(tetromino))
	{
		write(1, "error\n", 6);
		exit(0);
	}
	if (!(tt = (t_tetri *)malloc(sizeof(t_tetri))))
		exit(-1);
	*tt = format_tetri(tetromino, a);
	if (!(tt->square = ft_strnew(2 * 2)))
		exit(-1);
	tt->next = list_tetri(fd, a + 1);
	return (tt);
}

int		main(int ac, char *argv[1])
{
	char	*square;
	char	*final;
	t_tetri *first;
	int		fd;

	if (ac != 2 && write(1, "usage : fillit tetriminos_file\n", 31))
		return (0);
	fd = open(argv[1], O_RDONLY);
	first = list_tetri(fd, 'A');
	if (!(square = ft_strdup("....")))
		exit(-1);
	while (!(final = backtracking(square, ac++, 0, *first)))
	{
		alloc_tetri(first, ac * ac);
		ft_strdel(&square);
		if (!(square = ft_strnew(ac * ac)))
			exit(-1);
		ft_memset(square, '.', ac * ac);
	}
	free_tetri(first);
	put_square(final, ac - 1);
	ft_strdel(&final);
	close(fd);
	return (0);
}
