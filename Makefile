#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 22:19:25 by jbulant           #+#    #+#              #
#    Updated: 2017/11/17 00:59:38 by allauren         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

LIBFT = libft.a

SRCS = reader.c pieces_manager.c erroc.c dysplaytab.c\

OBJ = $(SRC=.c:.o)

INCLUDEPATH = libft/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDEPATH) $(INCLUDEPATH)$(LIBFT) $(SRCS) -o $(NAME)

$(LIBFT):
	@cd libft && make

clean:
	@cd libft && make clean

fclean:
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all
