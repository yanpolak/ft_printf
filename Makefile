# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 18:45:55 by ymarival          #+#    #+#              #
#    Updated: 2025/01/29 00:10:45 by ymarival         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Directories
INC_DIR = include/
SRC_DIR = srcs/
BONUS_DIR = srcs_bonus/
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRCS = ft_printf.c ft_fmt.c ft_read.c ft_print_chars.c ft_print_nbrs.c ft_print_hex.c
BONUS = ft_printf_bonus.c ft_fmt_bonus.c ft_read_bonus.c ft_print_chars_bonus.c \
         ft_print_nbrs_bonus.c ft_print_hex_bonus.c ft_print_hex_utils_bonus.c ft_print_nbrs_utils_bonus.c \

# Object files
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_DIR), $(BONUS:.c=.o))

# Include flags
INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I.

# Compilation rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
