/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:59:52 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/17 16:23:54 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

typedef short unsigned int		t_suint;

typedef struct				s_piece
{
	t_suint					value;
	unsigned char			max_x;
	int						pos_x;
	int						pos_y;
	unsigned char			max_y;
	unsigned long			mask;
}							t_piece;
typedef struct				s_map
{
	unsigned long			map[4];
	unsigned char			side_x;
	unsigned char			side_y;
}							t_map;
#define BUFF_SIZE 21
#define USAGE "usage: ./fillit source_file"
char							*print_tab(unsigned long *ul, char*);
void							parse(int fd);
t_piece							create_piece(char *tetrimino);
t_bool							buf_check(const char *buf);
void	print_bit(unsigned short *data, int size);

#endif
