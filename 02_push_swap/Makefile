# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acohaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:02:18 by acohaut           #+#    #+#              #
#    Updated: 2025/12/04 11:11:01 by acohaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror 
NAME		= push_swap
INCLUDES	= -I./includes -I./libft

LIBFT		= libft/libft.a

SRCS		= 	srcs/list_stack.c \
			srcs/list_utils.c \
			srcs/utils.c \
			srcs/operations.c \
			srcs/push_swap.c \
			srcs/checker.c \
			srcs/sorting.c \

#% regle pattern qui remplace n'importe quel chaine de caractere
OBJS		= $(SRCS:srcs/%.c=objs/%.o)

all:		$(NAME)

#Compilation de la Libft ; flag -C pour "change directory"
$(LIBFT):
		make -C libft

#creation directory des objs ; flag -p evite les erreurs si le dossier existe deja
objs:
		mkdir -p objs

#compilation des objs
objs/%.o:	srcs/%.c | objs
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
		rm -f $(OBJS)
		make clean -C libft

fclean:		clean
		rm -f $(NAME)
		make fclean -C libft

re:		fclean all

.PHONY:		all clean fclean re bonus
