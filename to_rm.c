/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:16:49 by allauren          #+#    #+#             */
/*   Updated: 2017/11/15 18:18:55 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	printf("msk_vert:%d\n", (1 | 1 << 4 | 1 << 8 | 1 << 12));
	return (0);
}
