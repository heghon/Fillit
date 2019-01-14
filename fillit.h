/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:59 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/14 13:54:05 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>		/* open */
# include <unistd.h>	/* read, close*/
# include <stdlib.h>	/*exit*/
# include "libft/libft.h"
# include "check.c"
//# include "backtracking.c"

int		four_connections(char *str);
int		is_valid(char *str);

#endif
