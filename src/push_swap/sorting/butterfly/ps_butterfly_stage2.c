/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_stage2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:39 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/18 12:41:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>
#include <limits.h>

static void	ps_preemptive_swap(t_stack *a, t_stack *b, int *next, t_list **list)
{
	if (b->values[b->size - 1] == *next)
	{
		ps_wrap_exec(PA, a, b, list);
		ps_wrap_exec(RA, a, b, list);
		*next += 1;
	}
}

static int	ps_preemptive_min(t_stack *a, t_stack *b, int idx)
{
	int		i;
	int		min;
	int		max;

	i = 0;
	min = INT_MAX;
	max = -1;
	if (a->values[0] != ps_stack_max(a))
		max = a->values[0];
	if (idx > (int)((float)b->size / 2.))
	{
		while (idx++ < (int)b->size - 1)
			if (b->values[idx] < min && b->values[idx] > max)
				min = b->values[idx];
	}
	else
		while (idx-- >= 0)
			if (b->values[idx] < min && b->values[idx] > max)
				min = b->values[idx];
	return (min);
}

static void	ps_tag_along(t_stack *a, t_stack *b, int idx, t_list **list)
{
	int		next;
	int		value;

	next = -1;
	if (a->size > 1)
		next = ps_preemptive_min(a, b, idx);
	value = b->values[idx];
	if (idx > (int)((float)b->size / 2.))
	{
		while (idx++ < (int)b->size - 1)
		{
			ps_wrap_exec(RB, a, b, list);
			if (next != -1 && next != value)
				ps_preemptive_swap(a, b, &next, list);
		}
	}
	else
	{
		while (idx-- >= 0)
		{
			ps_wrap_exec(RRB, a, b, list);
			if (next != -1 && next != value)
				ps_preemptive_swap(a, b, &next, list);
		}
	}
}

t_list	*ps_butterfly_stage2(t_stack *a, t_stack *b)
{
	t_list	*list;
	int		value;

	list = NULL;
	while (b->size > 0)
	{
		value = ps_stack_max(b);
		ps_tag_along(a, b, ps_stack_index(b, value), &list);
		ps_wrap_exec(PA, a, b, &list);
		while (a->size > 0 && a->values[0] == value - 1)
		{
			value -= 1;
			ps_wrap_exec(RRA, a, b, &list);
		}
		while (b->size == 0 && a->values[0] != ps_stack_max(a))
			ps_wrap_exec(RRA, a, b, &list);
	}
	return (list);
}
