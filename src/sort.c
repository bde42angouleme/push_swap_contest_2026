/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:04:15 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/21 18:55:30 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_be(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = ft_lstsize_stack(*a);
	if (size_a > 5)
	{
		while (ft_lstsize_stack(*a) > size_a / 2)
		{
			if ((*a)->index <= (unsigned int)(size_a / 2))
				pb(a, b);
			else if (ft_double_lstlast(*a)->index <= (unsigned int)(size_a / 2))
			{
				rra(a, 0);
				pb(a, b);
			}
			else
				ra(a, 0);
		}
	}
	while (ft_lstsize_stack(*a) > 3)
		pb(a, b);
	sort_three(a);
}

void	sort_three(t_stack **stack)
{
	if (find_min(*stack) == (*stack)->value)
	{
		if (find_max(*stack) == (*stack)->next->value)
		{
			sa(stack, 0);
			ra(stack, 0);
		}
	}
	else if (find_max(*stack) == (*stack)->value)
	{
		if (find_min(*stack) == (*stack)->next->value)
			ra(stack, 0);
		else
		{
			sa(stack, 0);
			rra(stack, 0);
		}
	}
	else
	{
		if (find_min(*stack) == (*stack)->next->value)
			sa(stack, 0);
		else
			rra(stack, 0);
	}
}

void	push_b_and_sort_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	t_index	*index;
	t_size	*size_a_b;
	int		cost;

	index = malloc(sizeof(t_index));
	size_a_b = malloc(sizeof(t_size));
	push_to_be(a, b);
	tmp_b = *b;
	while (*b)
	{
		index->j = 0;
		size_a_b->size_a = ft_lstsize_stack(*a);
		size_a_b->size_b = ft_lstsize_stack(*b);
		write_cost_b(a, tmp_b, index, size_a_b);
		cost = find_cost(*b);
		rotate_both(a, b, cost);
		pa(b, a);
		tmp_b = *b;
	}
	free(index);
	free(size_a_b);
}

void	sort(t_stack **a, t_stack **b)
{
	int		i;

	push_b_and_sort_a(a, b);
	i = find_index(*a, find_min(*a));
	while (!verif_order(*a))
	{
		if (i <= (ft_lstsize_stack(*a) / 2))
			ra(a, 0);
		else
			rra(a, 0);
	}
}
