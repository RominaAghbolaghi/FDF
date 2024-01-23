# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romina <romina@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 11:42:45 by rmohamma          #+#    #+#              #
#    Updated: 2023/05/06 13:26:45 by romina           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = ./includes/Libft/libft.a
PRINTF = ./includes/printf/libftprintf.a
GNL = ./includes/gnl/libgnl.a

SRCS = mandatory/main.c \
	mandatory/hook_events.c \
	mandatory/parsing.c \
	mandatory/rotation.c \
	mandatory/rotation_utils.c \
	mandatory/image_generation.c \
	mandatory/image_utils.c \
	mandatory/free.c \
	mandatory/ft_atoi_base.c 

B_SRCS =  bonus/main_bonus.c \
	bonus/hook_events_bonus.c \
	bonus/parsing_bonus.c \
	bonus/rotation_bonus.c \
	bonus/rotation_utils_bonus.c \
	bonus/image_generation_bonus.c \
	bonus/image_utils_bonus.c \
	bonus/free_bonus.c \
	bonus/ft_atoi_base_bonus.c

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)
bonus: ${BONUS}

$(NAME): $(OBJS)
	@ $(MAKE) -C ./includes/Libft
	@ $(MAKE) -C ./includes/printf
	@ $(MAKE) -C ./includes/minilibx-linux
	@ $(MAKE) -C ./includes/gnl
	@ gcc $(OBJS) -L includes/minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME) $(PRINTF) $(LIBFT) $(GNL)
	@ echo "$(GREEN)FDF Mandatory part created!$(DEFAULT)"

%.o: %.c
	@ gcc $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus:	$(B_OBJS)
	@ $(MAKE) -C ./includes/Libft
	@ $(MAKE) -C ./includes/printf
	@ $(MAKE) -C ./includes/minilibx-linux
	@ $(MAKE) -C ./includes/gnl
	@ gcc $(B_OBJS) -L includes/minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME) $(PRINTF) $(LIBFT) $(GNL)
	@ echo "$(GREEN)FDF Bonus part created!$(DEFAULT)"
			

clean:
	@ rm -f *.o
	@ $(MAKE) clean -C ./includes/Libft
	@ $(MAKE) clean -C ./includes/printf
	@ $(MAKE) clean -C ./includes/gnl
	@ echo "$(YELLOW)Objects files deleted!$(DEFAULT)"

fclean: clean
	@ rm -rf $(NAME)
	@ rm -rf $(OBJS)
	@ rm -rf $(B_OBJS)
	@ $(MAKE) fclean -C ./includes/Libft
	@ $(MAKE) fclean -C ./includes/printf
	@ $(MAKE) fclean -C ./includes/gnl
	@ echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all


#COLORS
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
DEFAULT	= \033[0m
