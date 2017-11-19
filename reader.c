/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/19 19:19:08 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_piece			*draw_map(t_piece *tetrimino)
{
	int				taille;
	unsigned short	map[16];
	char			tab[273];

	bzero(map, sizeof(unsigned short) * 16);
	memset(tab, '0', sizeof(char) * 272);
	tab[272] = '\0';
	taille = begin_size(tetrimino);
	while (!(ft_back(tetrimino, taille, map, 0)))
		taille++;
	print_bit(map, taille);
//	print_tab(tetrimino, taille, tab);
	return (tetrimino);
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
		tetri_tab[i++] = create_piece(buf);
		if (!buf_check(buf))
		{
			ft_putstr("error\n");
			return ;
		}
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
