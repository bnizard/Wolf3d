# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 16:33:30 by bnizard           #+#    #+#              #
#    Updated: 2014/05/16 14:26:32 by bnizard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

SRC		=	main.c \
			ft_memcpy.c \
			ft_strsplit.c \
			ft_strncpy.c \
			get_next_line.c \
			ft_atoi.c \
			ft_isdigit.c \
			stock_map.c \
			detect_wall.c \
			validity_map.c \
			draw.c \
			tools.c

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-I . -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11 -O3

all		:	$(NAME)

$(NAME)	:
			cc $(FLAGS) -o $(NAME) $(SRC)

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all
