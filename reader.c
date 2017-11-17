/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 19:01:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_bool		is_valid_pos(t_piece *tab, unsigned long *map)
{
	if(!(*map & tab->mask))
	{
		*map = *map ^ tab->mask;
		return (TRUE);
	}	
		return(FALSE);
}

int			count_tetri(t_piece *tab)
{
	int	i;

	i = 0;
	while (tab[i].value)
		i++;
	return (i);
}
int			begin_size(t_piece *tab)
{
	int	nb_tetri;
	int	sqrt;
	int	incr;
	int	odd;

	nb_tetri = 4 * count_tetri(tab);
	sqrt = 0;
	incr = 0;
	odd = 1;
	while (incr <= nb_tetri)
	{
		incr += odd;
		odd += 2;
		sqrt++;
	}
	if (((sqrt - 1) * (sqrt - 1)) == nb_tetri)
		sqrt--;
	return (sqrt);
}

t_bool		ft_backtrack(t_piece *tab, int size, unsigned short *map, int lvl)
{
	int	i;
	int	j;
	int	max_j;
	int max_i;

	max_j = size - tab[lvl].max_y;
	max_i = size - tab[lvl].max_x;
//	printf("lvl:%d,size:%d	size_tetri[%d][%d]	max[%d][%d]\n", lvl, size, tab[lvl].max_x, tab[lvl].max_y, max_i, max_j);
	j = -1;
	while (++j < max_j)
	{
		i = -1;
		while (++i < max_i)
		{
			if(is_valid_pos(tab + lvl, (unsigned long*)(map + j)))
			{
//				printf("tab[lvl + 1].value:%d\n", tab[lvl + 1].value);
				if ((!tab[lvl + 1].value || ft_backtrack(tab,size, map, lvl + 1))
						&& ((tab[lvl].pos_x = i) + 1)
						&& ((tab[lvl].pos_y = j) + 1))
					return (TRUE);
				*(unsigned long*)(map + j) ^= tab[lvl].mask;
			}
			tab[lvl].mask <<= 1;
		}
		if (max_i > 0)
			tab[lvl].mask >>= max_i;
	}
	return (FALSE);
}

void	print_tetri_mask(t_piece *tab)
{
	int	i;

	i = 0;
	while (tab[i].value)
	{
		printf("piece:%c:\n", (i + 'A'));
		print_bit((unsigned short*)(&tab[i].mask), 4);
		printf("\n");
		i++;
	}
}

t_piece	*draw_map(t_piece *tetrimino)
{
	int		taille;
	unsigned	short	map[16];
	char			tab[273];

	bzero(map, sizeof(unsigned short) * 16);
	bzero(tab, sizeof(char) * 273);

	/*
	map[0] = 0b1000000000000000;
	map[1] = 0b1100000000000000;
	map[2] = 0b1110000000000000;
	map[3] = 0b1111000000000000;
	map[4] = 0b1111100000000000;
	map[5] = 0b1111110000000000;
	map[6] = 0b1111111000000000;
	*/
	taille = begin_size(tetrimino);
	while (!(ft_backtrack( tetrimino, taille++, map, 0)));
//	ft_backtrack( tetrimino, taille++, map, 0);
	print_bit(map, 16);
	print_tetri_mask(tetrimino);
	return(tetrimino);

}

void			parse(int fd)
{
	static char		buf[BUFF_SIZE + 1];
	static t_piece	tetri_tab[26];
	int				ret;
	int				i;
	i = 0;
	while (i < 26)
		tetri_tab[i++].value = 0;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 1)
	{
		buf[ret] = '\0';
		if (!buf_check(buf))
		{
			ft_putstr("error\n");
			return ;
		}
		tetri_tab[i++] = create_piece(buf);
	}
	draw_map(tetri_tab);
}

int				main(int ac, const char **av)
{
	int fd;
	if (ac != 2)
	{
		ft_putendl(USAGE);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (1);
	parse(fd);
	return (0);
}
