/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 03:31:44 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char			*print_tab(unsigned long *ul, char *bitsArray)
{
	int i;
	int	u;
	char c;
	static int index = 0;
	//unsigned long mask = ~0x0;

	c = 'A' + index;
	i = 0;
	printf("%s", bitsArray);
	while(i < 4)
	{
	bitsArray[16 + 68 * i] = '\n';
	bitsArray[33 + 68 * i] = '\n';
	bitsArray[50 + 68 * i] = '\n';
	bitsArray[67 + 68 * i] = '\n';
	i++;
	}
	bitsArray[272] = '\0';
	i = 270;
	u = 3;
	printf("u vaut %lu\n", ul[1]);
	while (i > -1)
	{
		if (bitsArray[i] == '0')
		{
			bitsArray[i] = ul[u] % 2 + '0';
			if(bitsArray[i] == '1')
			{
				bitsArray [i] = c;
				printf("i vaut %d\n", i);
			}	
			ul[u] /= 2;
		}
		if(u)
		{
		if ((i / (u * 68)) == 1 && (i % (u * 68) == 0))
			u--;
		}
		i--;
	}
	index ++;
	printf("%s", bitsArray);
	return (bitsArray);
}
