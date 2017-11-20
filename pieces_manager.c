/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/20 07:50:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_suint					revers_bit(t_suint tetri)
{
	t_suint	rev;
	int		i;

	rev = 0;
	i = 0;
	while (i < 16)
	{
		rev |= (!!(tetri & (1 << (15 - i)))) << i;
		i++;
	}
	return (rev);
}

static void				set_size(t_piece *piece)
{
	t_suint	msk_hrz;
	t_suint	msk_vrt;
	int		i;

	msk_hrz = 0xF000;
	msk_vrt = 0X8888;
	i = 0;
	while (msk_hrz & piece->value && i < 4)
	{
		msk_hrz >>= 4;
		i++;
	}
	piece->max_y = i;
	i = 0;
	while (msk_vrt & piece->value && i < 4)
	{
		msk_vrt >>= 1;
		i++;
	}
	piece->max_x = i;
}

static t_suint			atosint(const char *tetrimino)
{
	t_suint			ret;
	unsigned int	c_count;
	size_t			i;

	ret = 0;
	c_count = 0;
	i = 20;
	while (i)
	{
		if (tetrimino[i - 1] == '#')
			ret |= 1 << c_count;
		if (tetrimino[i - 1] != '\n')
			c_count++;
		i--;
	}
	if (!ret)
		return (0);
	while (!(ret & 0x8888))
		ret <<= 1;
	while (!(ret & 0xF000))
		ret <<= 4;
	return (ret);
}

static unsigned long	sui_to_ul(t_suint mino)
{
	unsigned long	ul_mino;

	mino = revers_bit(mino);
	ul_mino = (mino & 0xF) | ((mino & 0xF0) << 12)
				| ((unsigned long)(mino & 0xF00) << (24))
				| ((unsigned long)(mino & 0xF000) << (36));
	return (ul_mino);
}

t_piece					create_piece(char *tetrimino)
{
	t_piece new;

	new.value = atosint(tetrimino);
	set_size(&new);
	new.mask = sui_to_ul(new.value);
	return (new);
}
