# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acohaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:02:18 by acohaut           #+#    #+#              #
#    Updated: 2026/01/16 18:04:28 by acohaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
NAME		= philo

SRCS		= 	srcs/main.c \
			srcs/utils.c \
			srcs/errors.c \
			srcs/initialisation.c \
			srcs/state.c \
			srcs/checks.c \

OBJS		= $(SRCS:srcs/%.c=objs/%.o)

all:		$(NAME)

objs:
		mkdir -p objs

objs/%.o: 	srcs/%.c  | objs
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
