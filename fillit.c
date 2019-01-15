/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/15 15:24:24 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int fd, char *argv[1])
/* Teste si tous les tetrominos de 'test_valid' sont valides.
 * Renvoie '-1' dans le cas contraire.
 */
{
	char	tetromino[21];
	t_tetri	tab_tetromino[26];
	int		i;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (read(fd,tetromino,21) > 0)
	{
		if (!is_valid(tetromino))
			exit(-1);
		//Example d'utilisation :
		tab_tetromino[0] = format_tetri(tetromino, 'A');
	}
	close(fd);
}
