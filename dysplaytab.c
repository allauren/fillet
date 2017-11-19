/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ultobits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/19 18:52:36 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

char			*print_tab(t_piece *ul,int taille, char *bitsArray)
{
/*	int i;
	int	u;
	char c;
	static int index = 0;
	int mask = 64;
	//unsigned long mask = ~0x0;
	i = 1;
	while(i < taille)
	{
	bitsArray[i * taille - 1] = '\n';
	//bitsArray[2 * taille + 2] = '\n';
	//bitsArray[50 + 68 * i] = '\n';
	//bitsArray[67 + 68 * i] = '\n';
	i++;
	}*/
	exit(0);
	/*
	bitsArray[(i - 1) * taille] ='\0';
	u = 0;
	printf("la map est \n%s   ------\n ", bitsArray);
	ft_print_ultobits(ul[1].mask);
	while(ul[u].mask)
	{
	c = 'A' + index;
	i = (i - 1) * taille - 1;
	while (i--) 
	{
		if(bitsArray != '\n')
		{
			if{ul[u].mask & 1 << mask;
			mask--;
			bitsArray[i] =
		}
		i--;
	}
	index++;
	}*/
	
	
	
/*
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
	index ++;*/
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
