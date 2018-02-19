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


NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./libft
INC_PATH = ./includes

SOURCES = ft_printf.c \
		ft_check_errors.c ft_check_flag.c ft_check_length.c \
		ft_check_precision.c ft_check_width.c ft_length_conversion.c \
		ft_pointer_address.c ft_printf_conversion.c ft_put_wchar.c \
		flag_c.c flag_d.c flag_p.c flag_s.c flag_u.c flag_x.c \
		flag_cap_C.c flag_cap_D.c flag_cap_O.c flag_cap_S.c \
		flag_cap_U.c flag_cap_X.c \
		 
OBJECTS = $(SOURCES:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SOURCES)) 
OBJ = $(addprefix $(OBJ_PATH),$(OBJECTS))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY : all clean fclean re

clean:
	rm -f $(OBJ)
	@rm -f $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
