# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 10:27:55 by aschukin          #+#    #+#              #
#    Updated: 2018/01/26 10:32:04 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SOURCES = ft_printf.c \


OBJECTS = $(SOURCES:.c=.o)

HEADER = printf.h

LIB = libft.a

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	@make re -C Libft/
	@$(CC) $(CFLAGS) -c $(SOURCES)
	@$(CC) $	(CFLAGS) -o $(NAME) Libft/$(LIB) $(OBJECTS)

clean:
	@make clean -C Libft/
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@make fclean -C Libft/
	@/bin/rm -f $(NAME)

re: fclean all
