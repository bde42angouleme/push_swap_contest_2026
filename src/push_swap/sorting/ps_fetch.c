/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fetch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:36 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 01:54:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

/**
 * @brief 	Fetches the element at the given index and puts it on top of the 
 * 			stack.
 * aka. ps_bon_toutou
 */
void	ps_fetch(t_stack *stack, size_t index, t_list **list, t_insn insns[2])
{
	int		middle;
	t_stack	*a;
	t_stack	*b;
	int		idx;

	a = stack;
	b = NULL;
	idx = index;
	if (insns[0] == RB)
		a = NULL;
	if (insns[0] == RB)
		b = stack;
	middle = (int)((float)stack->size / 2.);
	if (idx > middle)
	{
		while (idx++ < (int)stack->size - 1)
			ps_wrap_exec(insns[0], a, b, list);
	}
	else
	{
		while (idx-- >= 0)
			ps_wrap_exec(insns[1], a, b, list);
	}
}

size_t	ps_fetch_insns(t_stack *stack, size_t index)
{
	size_t	count;
	float	middle;
	int		idx;

	count = 0;
	idx = index;
	middle = (float)stack->size / 2;
	if (idx > middle)
	{
		while (idx++ < (int)stack->size - 1)
			count++;
	}
	else
	{
		while (idx-- >= 0)
			count++;
	}
	return (count);
}
