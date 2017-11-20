/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/20 08:06:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void		print_tab(t_piece *tetri, int size)
{
	char	map[273];
	int		i;
	int		x;
	int		y;

	ft_memset(map, '.', size * (size + 1));
	map[size * (size + 1)] = '\0';
	i = 0;
	while (i < size || !(i = -1))
		map[size + (i++ * (size + 1))] = '\n';
	while (tetri[++i].mask)
	{
		y = -1;
		while (++y < tetri[i].max_y)
		{
			x = -1;
			while (++x < size)
			{
				if (tetri[i].mask & (1UL << (x + (y * 16))))
					map[x + ((y + tetri[i].pos_y) * (size + 1))] = 'A' + i;
			}
		}
	}
	ft_putstr(map);
}

void		print_bit(unsigned short *data, int size)
{
	int		i;
	int		j;
	char	str[20];

	bzero(str, sizeof(str));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			str[j] = (data[i] & (1 << j)) ? '1' : '0';
			j++;
		}
		ft_putendl(str);
		i++;
	}
}
