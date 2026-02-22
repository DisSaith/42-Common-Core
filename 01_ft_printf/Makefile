# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acohaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:02:18 by acohaut           #+#    #+#              #
#    Updated: 2025/11/19 15:02:29 by acohaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -I includes
NAME		= libftprintf.a

SRCS		= 	ft_printf.c\
			ft_itoa.c\
			ft_itoa_unsigned.c\
			ft_printf_char.c\
			ft_printf_hexa.c\
			ft_printf_nbr.c\
			ft_printf_ptr.c\
			ft_printf_str.c\
			ft_printf_unsigned.c\
			ft_strlen.c\

OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	=	ft_printf_hash_bonus.c\
			ft_printf_sign_bonus.c\
			ft_printf_flags_bonus.c\
			ft_printf_bonus.c\
			ft_itoa.c\
			ft_itoa_unsigned.c\
			ft_printf_char.c\
			ft_printf_hexa.c\
			ft_printf_nbr.c\
			ft_printf_ptr.c\
			ft_printf_str.c\
			ft_printf_unsigned.c\
			ft_strlen.c\

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
		ar rcs $(NAME) $(BONUS_OBJS)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
