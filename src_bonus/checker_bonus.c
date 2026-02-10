/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:49:48 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/25 14:43:09 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	exec_rotations(char **orders, t_stack **a, t_stack **b, int i)
{
	if (ft_strncmp(orders[i], "ra", 3) == 0)
		ra(a);
	else if (ft_strncmp(orders[i], "rb", 3) == 0)
		rb(b);
	else if (ft_strncmp(orders[i], "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(orders[i], "rra", 3) == 0)
		rra(a);
	else if (ft_strncmp(orders[i], "rrb", 3) == 0)
		rrb(b);
	else if (ft_strncmp(orders[i], "rrr", 3) == 0)
		rrr(a, b);
	else
	{
		ft_lstfree(*a);
		ft_lstfree(*b);
		free_str(orders);
		ft_error();
	}
}

static void	exec_push_swap(char **orders, t_stack **a, t_stack **b, int i)
{
	if (ft_strncmp(orders[i], "pa", 3) == 0)
		pa(b, a);
	else if (ft_strncmp(orders[i], "pb", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(orders[i], "sa", 3) == 0)
		sa(a);
	else if (ft_strncmp(orders[i], "sb", 3) == 0)
		sb(b);
	else if (ft_strncmp(orders[i], "ss", 3) == 0)
		ss(a, b);
	else
		exec_rotations(orders, a, b, i);
}

static void	get_and_exec_orders(t_stack **stack_a, t_stack **stack_b)
{
	char	*order;
	char	*all_orders;
	char	**orders;
	int		i;

	i = 0;
	order = get_next_line(0);
	all_orders = NULL;
	if (order)
		all_orders = ft_strdup(order);
	while (order)
	{
		free(order);
		order = get_next_line(0);
		if (order)
			all_orders = ft_strjoin2(all_orders, order);
	}
	orders = ft_split(all_orders, '\n');
	free(all_orders);
	while (orders[i])
	{
		exec_push_swap(orders, stack_a, stack_b, i);
		i++;
	}
	free_str(orders);
}

static void	error_and_pars(int argc, char **argv, t_stack **stack_a)
{
	int	nbr;

	error_check(argc, argv);
	nbr = parsing(argc, argv, stack_a);
	if (!(*stack_a) || !dup_check(*stack_a) || nbr <= 1)
	{
		if (*stack_a)
			ft_lstfree(*stack_a);
		if (nbr <= 1)
			exit (1);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error_and_pars(argc, argv, &stack_a);
	get_and_exec_orders(&stack_a, &stack_b);
	if (verif_order(stack_a) && !stack_b)
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
}
