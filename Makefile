# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 21:19:50 by kiroussa          #+#    #+#              #
#    Updated: 2023/12/16 16:02:35 by kiroussa         ###   ########.fr        #
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

COMMON_SRC		=	insn/impl/ps_insn_pa.c \
					insn/impl/ps_insn_pb.c \
					insn/impl/ps_insn_ra.c \
					insn/impl/ps_insn_rb.c \
					insn/impl/ps_insn_rr.c \
					insn/impl/ps_insn_rra.c \
					insn/impl/ps_insn_rrb.c \
					insn/impl/ps_insn_rrr.c \
					insn/impl/ps_insn_sa.c \
					insn/impl/ps_insn_sb.c \
					insn/impl/ps_insn_ss.c \
					insn/ps_insn_exec.c \
					insn/ps_insn_from_name.c \
					insn/ps_insn_name.c \
					insn/ps_wrap_exec.c \
					stack/parser/ps_parse_stack.c \
					stack/public/ps_stack_push.c \
					stack/public/ps_stack_revrotate.c \
					stack/public/ps_stack_rotate.c \
					stack/public/ps_stack_swap.c \
					stack/query/ps_stack_bottom.c \
					stack/query/ps_stack_contains.c \
					stack/query/ps_stack_get.c \
					stack/query/ps_stack_index.c \
					stack/query/ps_stack_is_empty.c \
					stack/query/ps_stack_is_sorted.c \
					stack/query/ps_stack_max.c \
					stack/query/ps_stack_max_i.c \
					stack/query/ps_stack_min.c \
					stack/query/ps_stack_min_i.c \
					stack/query/ps_stack_top.c \
					stack/restricted/ps_stack_r_insert.c \
					stack/restricted/ps_stack_r_pop.c \
					stack/restricted/ps_stack_r_push.c \
					stack/restricted/ps_stack_r_remove.c \
					stack/ps_stack_clone.c \
					stack/ps_stack_free.c \
					stack/ps_stack_init.c \
					stack/ps_stack_print.c \
					stack/ps_stack_prints.c \
					stack/ps_stack_resize.c

PS_SRC			=	optimizer/ps_optimize.c \
					sorting/butterfly/ps_butterfly_sort.c \
					sorting/butterfly/ps_butterfly_stage1.c \
					sorting/butterfly/ps_butterfly_stage2.c \
					sorting/kroussar/ps_kroussar_sort.c \
					sorting/turk/ps_turk_sort.c \
					sorting/turk/ps_turk_stage1.c \
					sorting/turk/ps_turk_stage2.c \
					sorting/ps_fetch.c \
					sorting/ps_sort.c \
					sorting/ps_sort_small.c \
					sorting/ps_stack_normalize.c \
					main.c \
					ps_error.c

CHECKER_SRC		=	main.c

COMMON_SRC		:= $(addprefix $(COMMON_SRC_DIR)/, $(COMMON_SRC))
PS_SRC			:= $(addprefix $(PS_SRC_DIR)/, $(PS_SRC))
CHECKER_SRC		:= $(addprefix $(CHECKER_SRC_DIR)/, $(CHECKER_SRC))
COMMON_OBJ		= $(COMMON_SRC:.c=.o)
PS_OBJ			= $(PS_SRC:.c=.o)
CHECKER_OBJ		= $(CHECKER_SRC:.c=.o)

SRC_OBJS		= $(COMMON_OBJ) $(PS_OBJ)
BONUS_SRC_OBJS	= $(COMMON_OBJ) $(CHECKER_OBJ)

CC				= clang
CFLAGS			= -Wall -Wextra -Werror -g3
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
