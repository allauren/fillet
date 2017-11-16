/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 00:44:43 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*print_tab(unsigned long *ul, int index)
{
	static char bitsArray[273];
	int i;
	int	u;
	char c;

	c = 'A' + index;
	ft_memset(bitsArray, '0', 272);
	while(i < 4)
	{
	bitsArray[16 + 68 * i] = '\n';
	bitsArray[33 + 68 * i] = '\n';
	bitsArray[50 + 68 * i] = '\n';
	bitsArray[67 + 68 * i] = '\n';
	}
	bitsArray[272] = '\0';
	i = 0;
	u = 1;
	while (i != 0)
	{
		if (i % (u * 68))
			u++;
		if (bitsArray[i] != '\n')
		{
			bitsArray[i] = ul[u - 1] % 2 + '0';
			ul[u - 1] /= 2;
		}
		i++;
	}
	ft_putstr(bitsArray);
	return (bitsArray);
}
