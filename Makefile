NAME		= push_swap
NAME_BONUS	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

OBJ_DIR			= obj
OBJ_DIR_BONUS	= obj_bonus

SRCS 		= src/push_swap.c \
				src/swapers_pushers.c \
				src/rotators_up.c \
				src/rotators_down.c \
				src/lst_utils.c \
				src/parsing.c \
				src/utils.c \
				src/sort.c \
				src/write_index.c \
				src/write_cost.c \
				src/sort_utils.c

SRCS_BONUS	= src_bonus/checker_bonus.c \
				src_bonus/parsing_bonus.c \
				src_bonus/rotators_down_bonus.c \
				src_bonus/rotators_up_bonus.c \
				src_bonus/swapers_pushers_bonus.c \
				src_bonus/utils_bonus.c \
				src_bonus/lst_utils_bonus.c

OBJS		= $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:src_bonus/%.c=$(OBJ_DIR_BONUS)/%.o)

LIBFT_DIR	= includes/libft
LIB			= $(LIBFT_DIR)/libft.a
INCLUDES	= -I includes -I src -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "Push_swap OK\n"

bonus: $(LIB) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)
	@echo "Checker OK\n"


$(LIB):
	@make -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: src_bonus/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean: 
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects removed\n"

fclean: clean
	@$(RM) -r $(NAME)
	@$(RM) -r $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@echo "Push_swap and checker removed\n"

re: fclean all

re_bonus : fclean bonus

.PHONY : all clean fclean re bonus re_bonus
