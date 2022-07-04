# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelarose <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 12:31:59 by jelarose          #+#    #+#              #
#    Updated: 2020/02/24 18:05:24 by jelarose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  	srcs/ft_atoi.c srcs/ft_strjoin.c srcs/utile.c srcs/get_next_line_utils.c srcs/get_next_line.c srcs/win.c\
			srcs/grid.c srcs/ft_strcmp.c srcs/ft_split.c srcs/ft_itoa.c srcs/perso.c srcs/img.c srcs/ray.c srcs/color.c\
			srcs/parsing.c srcs/save.c srcs/list.c srcs/list2.c srcs/sprite.c srcs/print.c srcs/cube3d.c

SRCSBONUS	=	srcs/ft_atoi.c srcs/ft_strjoin.c srcs/utile.c srcs/get_next_line_utils.c srcs/get_next_line.c srcs/win.c\
			srcs/grid.c srcs/ft_strcmp.c srcs/ft_split.c srcs/ft_itoa.c srcs_bonus/perso_bonus.c srcs/img.c srcs/ray.c srcs/color.c\
			srcs/parsing.c srcs/save.c srcs/list.c srcs/list2.c srcs/sprite.c srcs/print.c srcs/cube3d.c

OBJS	= $(SRCS:.c=.o)

OBJSBONUS	= $(SRCSBONUS:.c=.o)

NAME	= Cub3d

CC	= gcc

CFLAGS	= -Ofast -flto -march=native -Wall -Wextra -Werror

all:		$(NAME) 

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

bonus:		fclean  $(OBJSBONUS)
			$(CC) $(CFLAGS) -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(OBJSBONUS) -o $(NAME)

clean:
			rm -f  $(OBJS) $(OBJSBONUS) 

fclean:	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
