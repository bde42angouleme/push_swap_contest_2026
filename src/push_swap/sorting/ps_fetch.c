/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fetch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:36 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 11:25:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

/**
 * aka. ps_bon_toutou
 */
void	ps_fetch(t_stack *stack, size_t index, t_list **list, t_insn insns[2])
{
	float	middle;
	t_stack	*a;
	t_stack	*b;

	a = stack;
	b = NULL;
	if (insns[0] == RB)
	{
		a = NULL;
		b = stack;
	}
	middle = ((float)stack->size) / 2. + .5;
	index = stack->size - index - 1;
	if (index < (size_t)middle)
		while (index-- > 0)
			ps_wrap_exec(insns[0], a, b, list);
	else
		while (index++ < stack->size)
			ps_wrap_exec(insns[1], a, b, list);
}

size_t	ps_fetch_insns(t_stack *stack, size_t index)
{
	size_t	count;
	float	middle;

	count = 0;
	middle = ((float)stack->size) / 2. + .5;
	index = stack->size - index - 1;
	if (index < (size_t)middle)
		while (index-- > 0)
			count++;
	else
		while (index++ < stack->size)
			count++;
	return (count);
}
