# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adhondt <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 21:33:32 by adhondt           #+#    #+#              #
#    Updated: 2018/05/28 16:42:57 by adhondt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = libftprintf.a

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	apply_flags.c apply_min_size.c apply_precision.c \
			apply_size_modifier.c data_initialization.c get_output_options.c \
			main.c print_c.c print_d_dd_u_i.c print_p.c print_s.c \
			print_x_xx_o_modulo.c \


LIB_NAME = 	ft_atoi.c ft_itoa.c ft_isdigit.c ft_strlen.c ft_memalloc.c \
			pos_in_str.c ft_memalloc_c.c ft_memset.c ft_strdup.c intlen.c \
			ft_putchar.c ft_putstr.c ft_putnchar.c ft_putnbr.c pf_putchar.c \
			pf_putstr.c pf_putnchar.c ft_litoa.c ft_strcpy.c \
			ft_strcnew.c ft_strncpy.c ft_chardup.c add_nfrontchar.c \
			add_frontchar.c add_nendchar.c ft_itoa_base.c ft_litoa_base.c \
			ft_strjoin_f.c ft_strcat.c ft_strcmp.c ft_strdup_f.c ft_uitoa.c \
			ft_uitoa_base.c ft_ulitoa_base.c ft_strnotchr.c ft_strjoin.c \
			ft_strstr.c ft_isalpha.c ft_isalpha_but.c \

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
