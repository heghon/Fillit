/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:27:44 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/14 13:34:12 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main()
/* Teste si tous les tetrominos de 'test_valid' sont valides.
 * Renvoie '-1' dans le cas contraire.
 */
{
	char tetromino[21];
	int file;

	file = open("test_valid", O_RDONLY);
	while (read(file,tetromino,21) > 0)
	{
		if (!is_valid(tetromino))
			exit(-1);
		ft_putstr("A valid tetromino was detected !\n");
	}
	close(file);
}
