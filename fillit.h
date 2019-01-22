/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:59 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/22 15:38:40 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>		/* open */
# include <unistd.h>	/* read, close*/
# include <stdlib.h>	/*exit*/
# include "libft/libft.h"

typedef struct       s_tetri
{
   int				h;
   int				l;
   char				*str;
   struct s_tetri	*next;
   char				*square;
}					t_tetri;

# include "check.c"
# include "solve.c"
#endif
