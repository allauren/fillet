/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:39:49 by allauren          #+#    #+#             */
/*   Updated: 2017/11/19 19:21:02 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_bool		is_valid_pos(t_piece *tab, unsigned long *map)
{
	if (!(*map & tab->mask))
	{
		*map = *map ^ tab->mask;
		return (TRUE);
	}
	return (FALSE);
}

int					count_tetri(t_piece *tab)
{
	int	i;

	i = 0;
	while (tab[i].value)
		i++;
	return (i);
}

int					begin_size(t_piece *tab)
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

t_bool				ft_back(t_piece *tab, int size, t_us *map, int lvl)
{
	t_s	s;

	ft_bzero(&s, sizeof(t_s));
	s.max_j = size - tab[lvl].max_y;
	s.max_i = size - tab[lvl].max_x;
	s.j = -1;
	while (++s.j < s.max_j)
	{
		s.i = -1;
		while (++s.i < s.max_i)
		{
			if(is_valid_pos(tab + lvl, (unsigned long*)(map + s.j)))
			{
				if (((!tab[lvl + 1].value || ft_back(tab, size, map, lvl + 1))
							&& ((tab[lvl].pos_x = s.i) + 1)
							&& ((tab[lvl].pos_y = s.j) + 1)))
					return (TRUE);
				*(unsigned long*)(map + s.j) ^= tab[lvl].mask;
			}
			tab[lvl].mask <<= 1;
		}
		if (s.max_i > 0)
			tab[lvl].mask >>= s.max_i;
	}
	return (FALSE);
}

void				print_tetri_mask(t_piece *tab)
{
	int	i;

	i = 0;
	while (tab[i].value)
	{
		printf("piece:%c:\n", (i + 'A'));
		print_bit((t_us*)(&tab[i].mask), 4);
		printf(" ");
		i++;
	}
}
