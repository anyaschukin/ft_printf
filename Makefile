# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 10:27:55 by aschukin          #+#    #+#              #
#    Updated: 2018/02/21 16:32:48 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = sources
SRC_NAME = ft_printf.c \
		ft_check_errors.c ft_check_flag.c ft_check_length.c \
		ft_check_precision.c ft_check_width.c ft_length_conversion.c \
		ft_pointer_address.c ft_printf_conversion.c ft_put_wchar.c \
		flag_c.c flag_d.c flag_p.c flag_s.c flag_u.c flag_x.c \
		flag_cap_C.c flag_cap_D.c flag_cap_O.c flag_cap_S.c \
		flag_cap_U.c flag_cap_X.c \
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = objects
OBJ_NAME = $(SRC_NAME:.c=.o)
	OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
	INC_PATH = include
	INC_NAME = ft_printf.h
	INCLUDES = $(addprefix $(INC_PATH)/,$(INC_NAME))
	#CFLAGS = -Wall -Werror -Wextra
	LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

libftcomp:
	@make all -C libft/

$(NAME): libftcomp $(OBJS) $(LIB)
	@libtool -static -o $(NAME) $(LIB) $(OBJS)
	@echo "\033[32;1m Compilation completed! \033[0m"

$(OBJS): $(OBJS_PATH) $(SRCS) $(INCLUDES_PATH)
	@gcc -c $(SRCS)
	@mv $(OBJS_NAME) $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH) 2> /dev/null || true

$(INCLUDES_PATH):
	@mkdir $(INCLUDES_PATH) 2> /dev/null || true
	@mv $(INCLUDE_NAME) $(INCLUDES_PATH)

clean:
	@make clean -C libft/
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@echo "\033[32;1m Cleanup Complete! \033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\033[32;1m Executables removed! \033[0m"

re: fclean all
