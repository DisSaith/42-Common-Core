# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acohaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:02:18 by acohaut           #+#    #+#              #
#    Updated: 2026/04/28 10:36:34 by acohaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g3
#CFLAGS		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
NAME		= interface

SRCS		= 	main.cpp \
				AMateria.cpp \
				Ice.cpp \
				Cure.cpp \
				Character.cpp \
				MateriaSource.cpp \

OBJS		= $(SRCS:%.cpp=objs/%.o)

all:		$(NAME)

objs:
		mkdir -p objs

objs/%.o: 	%.cpp  | objs
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS) ./objs

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
