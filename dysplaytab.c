/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 18:58:15 by allauren         ###   ########.fr       */
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
	printf("je suis la\n");
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
	return (bitsArray);
}
void	print_bit(unsigned short *data, int size)
{
	int		i;
	int		j;
	char	str[20];
	int		id;

	bzero(str, sizeof(str));
	i = 0;
	while (i < size)
	{
		j = 0;
//		id = (4 * (i / 4)) + (3 - (i % 4));
//		printf("i:%d	id:%d	(i %% 4):%d	3 - (i %% 4):%d\n", i, id, (i % 4), (3 - (i % 4)));
		id = i;
		while (j < 16)
		{
			str[j] = (data[id] & (1 << j)) ? '1': '0';
			j++;
		}
		printf("%s\n", str);
		i++;
	}
}
