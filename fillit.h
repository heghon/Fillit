/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:59 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/15 15:24:22 by bprunevi         ###   ########.fr       */
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
   int   h;
   int   l;
   char  *str;
}                    t_tetri;

/* Pourquoi redefinir ce qui est deja dans libft.h ?
typedef struct       s_list
{
   void           *content;
   size_t         content_size;
   struct s_list  *next;
}                    t_list;
*/

# include "check.c"
#endif
