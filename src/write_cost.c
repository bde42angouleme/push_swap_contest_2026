/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:04:09 by nredouan          #+#    #+#             */
/*   Updated: 2026/02/10 14:25:22 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_cost_b(t_stack **a, t_stack *tb, t_index *ind, t_size *size)
{
	t_stack	*ta;
	int		node;

	ta = *a;
	node = 0;
	while (tb)
	{
		ind->i = 0;
		node = find_node(a, &tb);
		while (ta && ta->value != node)
		{
			ta = ta->next;
			ind->i++;
		}
		if (ind->j <= size->size_b / 2)
			write_cost1(tb, ind, size);
		else
			write_cost2(tb, ind, size);
		calculate_double_rotation(tb);
		tb = tb->next;
		ta = *a;
		ind->j++;
	}
}

void	calculate_double_rotation(t_stack *tb)
{
	if (tb->ra && tb->rb)
	{
		if (tb->ra > tb->rb)
			tb->cost = tb->ra;
		else
			tb->cost = tb->rb;
	}
	else if (tb->rra && tb->rrb)
	{
		if (tb->rra > tb->rrb)
			tb->cost = tb->rra;
		else
			tb->cost = tb->rrb;
	}
}

void	write_cost1(t_stack *tmp_b, t_index *ind, t_size *size_a_b)
{
	if (ind->i <= size_a_b->size_a / 2)
	{
		tmp_b->cost = ind->i + ind->j;
		tmp_b->ra = ind->i;
		tmp_b->rra = 0;
	}
	else
	{
		tmp_b->cost = ind->j + (size_a_b->size_a - ind->i);
		tmp_b->rra = (size_a_b->size_a - ind->i);
		tmp_b->ra = 0;
	}
	tmp_b->rb = ind->j;
	tmp_b->rrb = 0;
}

void	write_cost2(t_stack *tmp_b, t_index *ind, t_size *size_a_b)
{
	if (ind->i <= size_a_b->size_a / 2)
	{
		tmp_b->cost = (size_a_b->size_b - ind->j) + ind->i;
		tmp_b->ra = ind->i;
		tmp_b->rra = 0;
	}
	else
	{
		tmp_b->cost = (size_a_b->size_b - ind->j) + (size_a_b->size_a - ind->i);
		tmp_b->rra = (size_a_b->size_a - ind->i);
		tmp_b->ra = 0;
	}
	tmp_b->rrb = (size_a_b->size_b - ind->j);
	tmp_b->rb = 0;
}
