/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:59 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/14 14:34:18 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>		/* open */
# include <unistd.h>	/* read, close*/
# include <stdlib.h>	/*exit*/
# include "libft/libft.h"
# include "check.c"

typedef struct     s_tetri
{
   int   height;
   int   width;
   char  *str;
}                  t_tetri;

#endif
