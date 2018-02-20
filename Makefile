# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 10:27:55 by aschukin          #+#    #+#              #
#    Updated: 2018/02/20 10:24:34 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = sources
OBJ_PATH = obj
INC_PATH = includes
LIB_PATH = libft

SOURCES = ft_printf.c \
		ft_check_errors.c ft_check_flag.c ft_check_length.c \
		ft_check_precision.c ft_check_width.c ft_length_conversion.c \
		ft_pointer_address.c ft_printf_conversion.c ft_put_wchar.c \
		flag_c.c flag_d.c flag_p.c flag_s.c flag_u.c flag_x.c \
		flag_cap_C.c flag_cap_D.c flag_cap_O.c flag_cap_S.c \
		flag_cap_U.c flag_cap_X.c \
		 

OBJECTS = $(SOURCES:.c=.o)
LIB = libft/libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJECTS))
INC = $(addprefix -I,$(INC_PATH))

.PHONY : all clean fclean re

all: $(NAME)


$(NAME): $(OBJ)
	@make -c libft/
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1m Compilation completed! \033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[32;1m Cleanup complete! \n\033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\033[32;1m Executables removed! \n\033[0m"

re: fclean all
