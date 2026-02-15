/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:20 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/15 14:39:46 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

/* --------------------------------- STRUCT -------------------------------- */

typedef struct s_lis
{
	int		*dp;
	int		*prev;
	int		*lis;
	size_t	size_lis;
	int		n;
	int		current_lis[3];
	int		best_lis[3];
}	t_lis;

typedef struct s_stack
{
	int		*tab;
	size_t	size;
}	t_stack;

typedef struct s_index
{
	int	*curent;
	int	*best;
}	t_index;

typedef struct s_cost
{
	int	ra_rb;
	int	rra_rrb;
	int	ra_rrb;
	int	rra_rb;
	int	*best;
}	t_cost;

/* --------------------------------- ENUM --------------------------------- */

typedef enum e_lis
{
	IDX = 0,
	INDEX_BV = 1,
	BEST_VALUE = 2
}	t_lis_type;

typedef enum e_move_type
{
	RA_RB = 1,
	RRA_RRB,
	RA_RRB,
	RRA_RB
}	t_move_type;

typedef enum e_utils
{
	ERROR = -1,
	FALSE = 0,
	TRUE = 1,
	N_CHUNK = 3
}	t_utils;

/* --------------------------------- MOVES --------------------------------- */

/* move_push.c */
char	*sa(t_stack *a, t_stack *b);
char	*sb(t_stack *a, t_stack *b);
char	*pa(t_stack *a, t_stack *b);
char	*pb(t_stack *a, t_stack *b);

/* move_rotate.c */
char	*ra(t_stack *a, t_stack *b);
char	*rb(t_stack *b, t_stack *a);
void	rr(t_stack *a, t_stack *b);

/* move_reverse_rotate.c */
char	*rra(t_stack *a, t_stack *b);
char	*rrb(t_stack *b, t_stack *a);
void	rrr(t_stack *a, t_stack *b);

/* ------------------------------- PARSING --------------------------------- */

/* parsing.c */
t_stack	*parsing(int ac, char **av);

/* -------------------------------- ALGO ----------------------------------- */

/* sort.c */
t_list	*algo_sort(t_stack *map, t_stack *b, int flag);
int		push_best_to_a(t_stack *map, t_stack *b, t_list **lst, int flag);

/* tiny_sort.c */
int		tiny_sort(t_stack *map, t_stack *b, t_list **lst);

/* sort_best_index.c */
int		*check_best_index(t_stack *map, t_stack *b);

/* opti_lst.c */
int		opti(t_list **lst);
void	del_pa_pb(t_list **lst, t_list *curent);
void	del_rb_rrb(t_list **lst, t_list *curent);
void	del_ra_rra(t_list **lst, t_list *curent);

/* sort_lis.c */
int		find_best_lis(t_lis *lis, t_stack *map);

/* -------------------------------- UTILS ---------------------------------- */

/* utils.c */
void	mapping(t_stack *a, t_stack *map);
int		new_cmd(t_list **lst, t_stack *stack1, t_stack *stack2,
			char *(*cmd)(t_stack *, t_stack *));
int		stack_sorted(t_stack *stack);

/* parsing_utils.c */
int		empty_str(char *str);
int		already_exit(t_stack *a, int nbr);

/* sort_utils.c */
int		check_previous_index_lis(t_stack *map, t_lis *lis);
void	init_dp_prev(t_lis *lis, int size);

/* opti_lst_utils.c */
int		*count_rr_or_rrr(t_list *curent, char *str1, char *str2, int size);
void	put_space(t_list *curent, int i, int flag);

/* ------------------------------- MEMORY ---------------------------------- */

/* memory.c */
t_stack	*init_stack(int ac, size_t size);
void	free_stack(t_stack *a, t_stack *b, t_stack *map);
void	free_tab_str(char **str);
void	free_and_null(void *p);

/* debug.c*/
void	print_stacks(t_stack *a, t_stack *b);
void	print_lis_on_stack(t_stack *a, int *lis);

#endif
