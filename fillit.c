/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/17 11:43:38 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int fd, char *argv[1])
/* Teste si tous les tetrominos de 'test_valid' sont valides.
 * Renvoie '-1' dans le cas contraire.
 */
{
	char	tetromino[21];
	char	b_tetri;
	t_tetro tetro;	
	t_tetri tetri;	
	int		i;

	fd = open(argv[1], O_RDONLY);
	//i = 0;
	while (read(fd,tetromino,21) > 0)
	{
		if (!is_valid(tetromino))
			exit(-1);
		//DEBUG TETRI
		tetri = format_tetri(tetromino, 'A');
		printf("\n%s\t %d  :  %d\n",tetri.str, tetri.h, tetri.l);

		//DEBUG BIN_TETRI
		b_tetri = bin_tetri(tetromino);
		show(b_tetri);

		// DEBUG TETRO
		tetro = stab_tetri(tetromino);
		i = -1;
		while (++i < tetro.h)
			printf("%s\n",tetro.str[i]);

		ft_putchar('\n');
	}
	close(fd);
}
