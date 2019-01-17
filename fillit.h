/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:59 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/17 11:48:39 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>		/* open */
# include <unistd.h>	/* read, close*/
# include <stdlib.h>	/*exit*/
# include "libft/libft.h"

// Debug
#include <stdio.h>
# define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c\t%c%c\n"
# define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 
#define show(x) printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));


typedef struct       s_tetri
{
   int   h;
   int   l;
   char  *str;
}                    t_tetri;

typedef struct       s_tetro
{
   int   h;
   int   l;
   char  **str;
}                    t_tetro;

# include "check.c"
#endif
