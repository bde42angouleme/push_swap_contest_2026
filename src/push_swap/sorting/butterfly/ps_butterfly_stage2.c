/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_stage2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:39 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 10:00:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

static int	ps_preemptive_swap(t_stack *a, t_stack *b, int* next, t_list **list)
{
	if (b->values[b->size - 1] == *next)
	{
		ps_wrap_exec(PA, a, b, list);
		ps_wrap_exec(RA, a, b, list);
		*next += 1;
		return (1);
	}
	return (0);
}

static size_t	ps_preemptive_lookup(t_stack *stack, int idx)
{
	int	n_preemptive;
	int	last_n;

	last_n = 0;
	while (stack)
	{
		n_preemptive = 0;
		if (idx > (int)((float)stack->size / 2.))
		{
			while (idx++ < (int)stack->size - 1)
			{
				ps_wrap_exec(RB, NULL, stack, NULL);
				if (stack->values[stack->size - 1] - (n_preemptive + 1) == stack->values[idx])
					n_preemptive++;
			}
		}
		else
		{
			while (idx-- >= 0)
			{
				ps_wrap_exec(RRB, NULL, stack, NULL);
				if (stack->values[stack->size - 1] - (n_preemptive + 1) == stack->values[idx])
					n_preemptive++;
			}
		}
		if (last_n == n_preemptive)
			break ;
		last_n = n_preemptive;
	}
	ps_stack_free(&stack);
	return (n_preemptive);
}

static int	ps_tag_along(t_stack *a, t_stack *b, int idx, t_list **list)
{
	int		moves;
	int		moves_tmp;
	int		next;

	moves = ps_preemptive_lookup(ps_stack_clone(b), idx);
	moves_tmp = moves;
	next = b->values[idx] - moves;
	if (idx > (int)((float)b->size / 2.))
	{
		while (idx++ < (int)b->size - 1)
		{
			ps_wrap_exec(RB, a, b, list);
			if (moves-- > 0)
				ps_preemptive_swap(a, b, &next, list);
		}
	}
	else
	{
		while (idx-- >= 0)
		{
			ps_wrap_exec(RRB, a, b, list);
			if (moves-- > 0)
				ps_preemptive_swap(a, b, &next, list);
		}
	}
	return (moves_tmp);
}

t_list	*ps_butterfly_stage2(t_stack *a, t_stack *b)
{
	t_list	*list;
	int		value;
	int		n_insn;

	list = NULL;
	while (b->size > 0)
	{
		value = ps_stack_max(b);
		n_insn = ps_tag_along(a, b, ps_stack_index(b, value), &list);
		ps_wrap_exec(PA, a, b, &list);
		while (n_insn-- > 0)
		{
			ps_wrap_exec(RRA, a, b, &list);
		}
	}
	return (list);
}
