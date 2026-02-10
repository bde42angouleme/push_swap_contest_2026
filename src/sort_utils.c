/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:05:06 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 17:01:49 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_cost(t_stack *b)
{
	int	cheapest;

	cheapest = b->cost;
	while (b)
	{
		if (b->cost < cheapest)
			cheapest = b->cost;
		b = b->next;
	}
	return (cheapest);
}

int	find_index(t_stack *stack, int target)
{
	int	index;

	index = 0;
	while (stack->value != target)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	find_node(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		node;

	tmp = *a;
	node = find_max(*a);
	if ((*b)->value > node || (*b)->value < find_min(*a))
		return (find_min(*a));
	while (tmp)
	{
		if (tmp->value > (*b)->value && tmp->value < node)
			node = tmp->value;
		tmp = tmp->next;
	}
	return (node);
}

void	rotate_both(t_stack **a, t_stack **b, int cost)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp->cost != cost)
		tmp = tmp->next;
	while (tmp->ra && tmp->rb)
	{
		rr(a, b);
		tmp->ra--;
		tmp->rb--;
	}
	while (tmp->rra && tmp->rrb)
	{
		rrr(a, b);
		tmp->rra--;
		tmp->rrb--;
	}
	finish_rotate(a, b, tmp);
}

void	finish_rotate(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->ra)
	{
		ra(a, 0);
		node->ra--;
	}
	while (node->rra)
	{
		rra(a, 0);
		node->rra--;
	}
	while (node->rb)
	{
		rb(b, 0);
		node->rb--;
	}
	while (node->rrb)
	{
		rrb(b, 0);
		node->rrb--;
	}
}
