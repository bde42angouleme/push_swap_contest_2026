/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_stage1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:27:47 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 19:11:45 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PS_BUTTERFLY_SORT
#include <ps/sort.h>
#include <limits.h>

static int	ps_find_value(t_stack *stack, size_t min_value, size_t max_value)
{
	size_t	i;
	size_t	min_index;
	size_t	min_travel;

	i = 0;
	min_travel = INT_MAX;
	while (i < stack->size)
	{
		if (stack->values[i] >= (int)min_value
			&& stack->values[i] < (int)max_value)
		{
			if (min_travel > ps_fetch_insns(stack, i))
			{
				min_travel = ps_fetch_insns(stack, i);
				min_index = i;
			}
		}
		i++;
	}
	return (stack->values[min_index]);
}

static t_list	*ps_handle_box(t_stack *a, t_stack *b, size_t bi, size_t per)
{
	t_list	*list;
	size_t	count;
	size_t	min;
	size_t	max;
	int		value;

	list = NULL;
	count = 0;
	min = bi * per;
	max = (bi + 1) * per;
	while (a->size > 0 && count < per)
	{
		value = ps_find_value(a, min, max);
		ps_fetch(a, ps_stack_index(a, value), &list, (t_insn[2]){RA, RRA});
		ps_wrap_exec(PB, a, b, &list);
		if (value < (int)(min + per / 2))
			ps_wrap_exec(RB, a, b, &list);
		count++;
	}
	return (list);
}

t_list	*ps_butterfly_stage1(t_stack *a, t_stack *b, size_t n, size_t per_box)
{
	t_list	*list;
	size_t	i;

	list = NULL;
	i = 0;
	while (i < n)
	{
		ft_lst_add(&list, ps_handle_box(a, b, i, per_box));
		i++;
	}
	return (list);
}
