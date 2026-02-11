/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:27:27 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/10 14:39:37 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

//struct
typedef struct s_stack
{
	int				cost;
	unsigned int	index;
	long long int	value;
	struct s_stack	*previous;	
	struct s_stack	*next;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}					t_stack;

typedef struct s_index
{
	int	i;
	int	j;
}		t_index;

typedef struct s_size
{
	int	size_a;
	int	size_b;
}		t_size;

//errors check
int		error_check(int argc, char **argv);
int		dup_check(t_stack *stack_a);
void	ft_error(void);

//stack creation
t_stack	*ft_double_lstlast(t_stack *lst);
t_stack	*ft_double_lstnew(long long int value);
void	free_str(char **str);
void	ft_lstfree(t_stack *lst);
void	new_node(char *splitter, t_stack *stack_a);
int		parsing(int argc, char **argv, t_stack **stack_a);

//stack modificators
void	sa(t_stack **stack, int i);
void	pa(t_stack **src, t_stack **dest);
void	pb(t_stack **src, t_stack **dest);
void	ra(t_stack **stack, int i);
void	rb(t_stack **stack, int i);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack, int i);
void	rrb(t_stack **stack, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//utils for stack navigation
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_node(t_stack **a, t_stack **b);
int		find_index(t_stack *stack, int target);
int		find_cost(t_stack *b);
int		ft_lstsize_stack(t_stack *lst);
int		verif_order(t_stack *stack);

//sorts functions
void	sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
void	rotate_both(t_stack **a, t_stack **b, int cost);
void	finish_rotate(t_stack **a, t_stack **b, t_stack *node);
void	push_to_be(t_stack **a, t_stack **b);
void	write_cost_b(t_stack **a, t_stack *tb, t_index *ind, t_size *size);
void	write_cost1(t_stack *tmp_b, t_index *index, t_size *size_a_b);
void	write_cost2(t_stack *tmp_b, t_index *index, t_size *size_a_b);
void	calculate_double_rotation(t_stack *tb);

//array function
void	write_index(t_stack *stack_a, int nbr);

#endif
