/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:43:25 by bmenant           #+#    #+#             */
/*   Updated: 2019/01/09 19:59:23 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_the_tetra(char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if(tab[i][j] == 35)
				k++;
			if ((k > 1 && i == 0) && tab[i][j - 1] != 35)
				return (0);
			else if ((k > 1 && i > 0 && j == 0) && (tab[i - 1][j] != 35))
				return (0);
			else if ((k > 1 && i > 0 && j > 0) &&
					(tab[i - 1][j] != 35 || tab[i][j - 1] != 35))
				return (0);
		}
	}
	return (1);
}

int		check_the_tab(char **tab)
{
	int		i;
	int		j;
	int		nb_char;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 35 && tab[i][j] != 46)
				return (0);
			else if (tab[i][j++] == 35)
				nb_char++;
			j++;
		}
		if (j != 4)
			return (0);
		i++;
	}
	if (i != 4 || nb_char != 4)
		return (0);
	else
		return (1);
}

int		check_the_file(int fd, char *argv[1])
{
	char	**tab;
	char	*line;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 5)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * 5)))
			return (0);
		if (ft_strlen(line) == 4)
			tab[i] = line;
		tab[i][4] = "\0";
		else if (line == "\n")
		{
			if (check_the_tab(tab) == 0 || check_the_tetra(tab) == 0)
				return (0);
			i = -1;
		}
		i++;
		free(line);
	}
	tab[i] = 0;
	close (fd);
	return (1);
}
