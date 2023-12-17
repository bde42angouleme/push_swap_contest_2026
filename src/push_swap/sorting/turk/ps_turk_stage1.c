/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_stage1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:03:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 00:01:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ft/print.h>
#include <ps/sort.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Finds where a certain value would fit best on the stack
 */
static size_t	ps_find_best_index(t_stack *stack, int val)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] == val + 1)
		{
			ft_printf("  %d shoukd be inserted before %d\n", val, stack->values[i]);
			if (i == 0)
				return (stack->size - 1);
			return (i - 1);
		}
		i++;
	}
	return (0);
}

static int	ps_distance(size_t idx1, size_t idx2, size_t size)
{
	int		dist_between;
	int		dist_to_side1;
	int		dist_to_side2;
	int		dist_around;
	float	middle;

	middle = (size_t)(((float)size) / 2. + .5);
	dist_between = ft_abs((int)idx1 - (int)idx2);
	if (idx1 < middle)
	{
		dist_to_side1 = idx1;
		dist_to_side2 = size - idx2;
	}
	else
	{
		dist_to_side1 = size - idx1;
		dist_to_side2 = idx2;
	}
	dist_around = ft_abs(dist_to_side1 + dist_to_side2);
	if (dist_around < dist_between)
		return (dist_around);
	return (dist_between);
}

static size_t	ps_calc(t_stack *stack, size_t index, int val, bool insert)
{
	size_t	best_index;
	size_t	moves;

	moves = 0;
	best_index = stack->size - 1;
	if (insert)
	{
		best_index = ps_find_best_index(stack, val);
		ps_stack_r_push(stack, val);
	}
	moves = ps_distance(index, best_index, stack->size);
	if (insert)
		ps_stack_r_pop(stack);
	return (moves);
}

static size_t	ps_find_best_target(t_stack *a, t_stack *b)
{
	size_t	index;
	size_t	best_index;
	size_t	insns;
	size_t	best_insns;
	int		val;

	index = 0;
	best_index = 0;
	best_insns = INT_MAX;
	while (index < a->size)
	{
		val = ps_stack_get(a, index);
		ft_printf("\n try stack[%u] = %d?\n", index, val);
		size_t to_up = ps_calc(a, index, val, false);
		size_t to_target = ps_calc(b, index, val, true);
		insns = to_up + 1 + to_target;
		if (insns < best_insns)
		{
			best_insns = insns;
			best_index = index;
		}
		index++;
	}
	return (best_index);
}

void	ps_turk_stage1(t_stack *a, t_stack *b, t_list **list)
{
	size_t	index;

	(void)a;
	(void)b;
	(void)list;
	ps_stack_prints(a, b);
	ft_printf("Trying to find the best value to move...\n");
	index = ps_find_best_target(a, b);
	ft_printf("GOT stack[%u] = %d\n", index, ps_stack_get(a, index));
}
