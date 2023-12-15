/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_stage2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:39 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 15:08:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PS_BUTTERFLY_SORT
#include <ps/sort.h>

static int	ps_get_best_value(t_stack *stack, int *shortcut)
{
	size_t	insns;
	size_t	insns2;
	int		max;

	max = ps_stack_max(stack);
	if (shortcut && *shortcut)
	{
		*shortcut = 0;
		return (max);
	}
	insns = ps_fetch_insns(stack, ps_stack_index(stack, max));
	insns2 = ps_fetch_insns(stack, ps_stack_index(stack, max - 1));
	if (insns2 < insns)
	{
		if (shortcut)
			*shortcut = 1;
		return (max - 1);
	}
	return (max);
}

t_list	*ps_butterfly_stage2(t_stack *a, t_stack *b)
{
	t_list	*list;
	int		value;
	int		shortcut;

	list = NULL;
	shortcut = 0;
	while (b->size > 0)
	{
		value = ps_get_best_value(b, &shortcut);
		ps_fetch(b, ps_stack_index(b, value), &list, (t_insn[2]){RB, RRB});
		ps_wrap_exec(PA, a, b, &list);
		if (a->size >= 2 && a->values[a->size - 1] > a->values[a->size - 2])
		{
			if (b->size > 2 && ps_stack_index(b, ps_get_best_value(b, NULL))
				== (int) (b->size - 2))
				ps_wrap_exec(SS, a, b, &list);
			else
				ps_wrap_exec(SA, a, b, &list);
		}
	}
	return (list);
}
