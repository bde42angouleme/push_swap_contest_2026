# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/11/18 04:43:15 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRC		= libft
LIBFT			= $(LIBFT_SRC)/build/output/libft.a

NAME			= push_swap
BONUS_NAME		= checker

INCLUDES		= ./include
SRC_FOLDER		= src

COMMON_SRC_DIR	= $(SRC_FOLDER)/shared
PS_SRC_DIR		= $(SRC_FOLDER)/push_swap
CHECKER_SRC_DIR	= $(SRC_FOLDER)/checker

COMMON_SRC		=	stack/ps_stack_free.c \
					stack/ps_stack_init.c \
					stack/ps_stack_print.c \
					stack/ps_stack_resize.c \
					stack/public/ps_stack_push.c \
					stack/public/ps_stack_revrotate.c \
					stack/public/ps_stack_rotate.c \
					stack/public/ps_stack_swap.c \
					stack/query/ps_stack_bottom.c \
					stack/query/ps_stack_get.c \
					stack/query/ps_stack_is_empty.c \
					stack/query/ps_stack_top.c \
					stack/restricted/ps_stack_r_insert.c \
					stack/restricted/ps_stack_r_pop.c \
					stack/restricted/ps_stack_r_push.c \
					stack/restricted/ps_stack_r_remove.c

PS_SRC			= main.c
CHECKER_SRC		= main.c

COMMON_SRC		:= $(addprefix $(COMMON_SRC_DIR)/, $(COMMON_SRC))
PS_SRC			:= $(addprefix $(PS_SRC_DIR)/, $(PS_SRC))
CHECKER_SRC		:= $(addprefix $(CHECKER_SRC_DIR)/, $(CHECKER_SRC))
COMMON_OBJ		= $(COMMON_SRC:.c=.o)
PS_OBJ			= $(PS_SRC:.c=.o)
CHECKER_OBJ		= $(CHECKER_SRC:.c=.o)

SRC_OBJS		= $(COMMON_OBJ) $(PS_OBJ)
BONUS_SRC_OBJS	= $(COMMON_OBJ) $(CHECKER_OBJ)

CC				= clang
CFLAGS			= -Wall -Wextra -Werror
COPTS			= -I $(INCLUDES) -I $(LIBFT_SRC)/include

all:			$(NAME)

$(NAME):		$(LIBFT) $(SRC_OBJS)
	$(CC) $(CFLAGS) $(COPTS) $(SRC_OBJS) -o $(NAME) $(LIBFT)

bonus:			$(BONUS_NAME)

$(BONUS_NAME):	$(LIBFT) $(BONUS_SRC_OBJS)
	$(CC) $(CFLAGS) $(COPTS) $(BONUS_SRC_OBJS) -o $(BONUS_NAME) $(LIBFT)

$(LIBFT): 
	make -C $(LIBFT_SRC) -j$(shell nproc) CFLAGS="$(CFLAGS)"

%.o:			%.c
	$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

clean:
	make -C $(LIBFT_SRC) clean
	rm -f $(COMMON_OBJ) $(PS_OBJ) $(CHECKER_OBJ)

fclean:			clean
	make -C $(LIBFT_SRC) fclean
	rm -f $(NAME) $(BONUS_NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re
