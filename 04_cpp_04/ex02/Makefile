# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acohaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 15:02:18 by acohaut           #+#    #+#              #
#    Updated: 2026/04/24 14:24:38 by acohaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= animal02

SRCS		= 	main.cpp \
				AAnimal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				Brain.cpp \

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
