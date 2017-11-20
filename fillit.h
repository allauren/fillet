/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:59:52 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/20 08:02:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 21
# define USAGE "usage: ./fillit source_file"

typedef short unsigned int	t_suint;
typedef unsigned short		t_us;

typedef struct			s_piece
{
	t_suint			value;
	unsigned char	max_x;
	int				pos_x;
	int				pos_y;
	unsigned char	max_y;
	unsigned long	mask;
}						t_piece;
typedef struct			s_back
{
	int	i;
	int	j;
	int	max_j;
	int	max_i;
}						t_s;
void					print_tab(t_piece *tetri, int grid_size);
int						parse(int fd);
t_piece					create_piece(char *tetrimino);
t_bool					buf_check(const char *buf);
t_bool					ft_back(t_piece *tab, int size, t_us *map, int lvl);
int						begin_size(t_piece *tab);
int						is_valide(t_suint value);
#endif
