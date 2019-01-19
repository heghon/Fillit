# include <fcntl.h>        /* PAS LOIN REVOIR LES CONDITIONS DE DEPLACEMENTS */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char    *ft_strnew(size_t size)
{
	char    *str;
	size_t    i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}

void    *ft_memset(void *str, int c, size_t n)
{
	size_t    i;
	char    *string;

	string = (char *)str;
	i = 0;
	while (i != n)
	{
		string[i] = c;
		i++;
	}
	return (string);
}

typedef struct       s_tetri
{
	int                h;
	int                l;
	char                *str;
	struct s_tetri    *next;
}                    t_tetri;

void    delete_before(t_tetri *tetri, int side, int s, char *final_str)
{
	int        i;
	int         start;

	start = s;
	i = 0;
	while (tetri->str[i])
	{
		final_str[s] = '.';
		if (((s + 1) % side) == 0 && ((s + 1) / side) > 0)
			s += side - tetri->l + 1;
		else if ((s % side) + 1 == (start % side) + tetri->l)
			s += side - tetri->l + 1;
		else
			s++;
		i++;
	}
}

int        verification(t_tetri *tetri, int side, int s, char *final_str)
{
	int        i;
	int         start;

	start = s;
	i = 0;
	if (s == side * side)
		return (-1);
	if (((tetri->l + (start % side) - 1) > side) || ((tetri->h + (start / side)) - 1 > side))
		return (0);
	while (tetri->str[i])
	{
		if (final_str[s] != '.' && tetri->str[i] != '.')
			return (0);
		if (((s + 1) % side) == 0 && ((s + 1) / side) > 0)
			s += side - tetri->l + 1;
		else if ((s % side) + 1 == (start % side) + tetri->l)
			s += side - tetri->l + 1;
		else
			s++;
		i++;
	}
	return (1);
}

void    placement(t_tetri *tetri, int side, char *final_str, int s)
{
	int        i;
	int start;

	start = s;
	i = 0;
	while (tetri->str[i])
	{
		final_str[s] = tetri->str[i];
		if (((s + 1) % side) == 0 && ((s + 1) / side) > 0)
			s += side - tetri->l + 1;
		else if ((s % side) + 1 == (start % side) + tetri->l)
			s += side - tetri->l + 1;
		else
			s++;
		i++;
	}
}

char    *resolve(t_tetri *tetri, int side, int start, char *final_str)
	/* on doit commencer start a 0 et side a 2 */
{
	int                    ret;
	static unsigned int    i = 0;
	int             backstart[26];
	t_tetri          *backup[26]; 
	if (i == 0)
	{
		final_str = ft_strnew((size_t)(side * side));
		final_str = ft_memset(final_str, '.', (side * side));
	}
	while (tetri)
	{
		backstart[i] = start;
		ret = verification(tetri, side, backstart[i], final_str);
		if (ret == 0)
			start++;
		else if (ret == -1)
		{
			if (i == 0){
				free(final_str);
				final_str = resolve(tetri, ++side, 0, final_str);
			}
			else
			{
				delete_before(backup[i - 1], side, backstart[i - 1], final_str);
				i--;
				backstart[i]++;
				final_str = resolve(backup[i], side, backstart[i], final_str);
			}
		}
		else
		{
			placement(tetri, side, final_str, backstart[i]);
			backup[i++] = tetri; /* le backup se fait seulement apres un placement*/
			start++;
			tetri = tetri->next;
		}
	}
	return (final_str);
}

int main()
{
	t_tetri    *tetri1;
	t_tetri    *tetri2;
	t_tetri     *tetri3;
	char    str1[] = "AAAA";
	char    str2[] = "BBB.B.";
	char    str3[] = "CCCC";
	char *final_str;
	int        i = 0;

	tetri1 = (t_tetri *)malloc(sizeof(t_tetri));
	tetri2 = (t_tetri *)malloc(sizeof(t_tetri));
	tetri3 = (t_tetri *)malloc(sizeof(t_tetri));
	tetri1->l = 1;
	tetri1->h = 4;
	tetri1->str = str1;
	tetri2->l = 2;
	tetri2->h = 3;
	tetri2->str = str2;
	tetri3->l = 4;
	tetri3->h = 1;
	tetri3->str = str3;
	tetri1->next = tetri2;
	tetri2->next = tetri3;
	tetri3->next = NULL;
	final_str = resolve(tetri1, 2, 0, final_str);
	while (final_str[i])
	{
		write(1, &final_str[i], 1);
		i++;
		if (i % 4 == 0)
			write (1, "\n", 1);
	}
	return (0);
}
