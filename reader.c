/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 03:30:04 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	draw_map(t_piece *tetrimino)
{
//	ft_bzero(map, 32);

	for (int i = 0; i < 26; i++)
	{
		if (tetrimino[i].value == 0)
			break ;
		ft_print_ultobits(tetrimino[i].mask);
		ft_putchar('\n');
	}
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
	static char bitsArray[273];
	memset(bitsArray, '0', 272);
	unsigned long	tab[4];
	bzero(tab, sizeof(unsigned long) * 4);
	tab[0] = tetri_tab[0].mask;
	print_tab(tab, bitsArray);
	tab[1] = tetri_tab[1].mask;
	tab[0] = 0;
	print_tab(tab, bitsArray);
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
