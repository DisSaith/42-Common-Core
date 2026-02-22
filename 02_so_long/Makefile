# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acohaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:02:18 by acohaut           #+#    #+#              #
#    Updated: 2026/01/09 13:32:33 by acohaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= so_long
INCLUDES	= -I includes -I./libft

LIBFT		= libft/libft.a

SRCS		= 	sources/main.c \
			sources/sprite.c \
			sources/rendering_game.c \
			sources/checker.c \
			sources/utils.c \
			sources/flood_fill.c \
			sources/errors.c \

OBJS		= $(SRCS:.c=.o)

SRCS_BONUS	= 	sources_bonus/main_bonus.c \
			sources_bonus/sprite_bonus.c \
			sources_bonus/rendering_game_bonus.c \
			sources_bonus/checker_bonus.c \
			sources_bonus/utils_bonus.c \
			sources_bonus/flood_fill_bonus.c \
			sources_bonus/movements_bonus.c \
			sources_bonus/errors_bonus.c \

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

$(LIBFT):
		make -C libft

%.o: %.c 
		$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME):	$(LIBFT) $(OBJS)
		make -C mlx_linux
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus:		$(LIBFT) $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
		rm -f $(OBJS) $(OBJS_BONUS)
		make clean -C libft

fclean:		clean
		rm -f $(NAME)
		make fclean -C libft

re:		fclean all

.PHONY:		all clean fclean re bonus
