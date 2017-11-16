/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 00:49:02 by allauren         ###   ########.fr       */
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
