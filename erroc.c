/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:07:57 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/19 19:24:59 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

int			is_valide(t_suint value)
{
	static	t_suint all[19] = {61440, 34952, 52224, 51328, 57856, 17600, 36352,
								35008, 59392, 50240, 11776, 50688,
								19584, 35904, 27648, 35968, 58368,
								19520, 19968};
	int		i;

	i = -1;
	while (++i < 19)
	{
		if (value == all[i]) 
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	buf_check(const char *buf)
{
	unsigned int i;
	
	i = 0;
	while (buf[i])
	{
		if ( i % 5 == 4 && buf[i] != '\n')
		{	
			return (FALSE);
		}
		if (buf[i] != '.' && buf[i] != '#' &&  buf[i] != '\n')
		{
			return (FALSE);
		}
			i++;
	}
	return (TRUE);
}
