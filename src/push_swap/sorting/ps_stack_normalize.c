/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_normalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:47:11 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 01:55:26 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

static size_t	ps_fabricate_index(t_stack *stack, int number)
{
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < number)
			index++;
		i++;
	}
	return (index);
}

t_stack	*ps_stack_normalize(t_stack *stack)
{
	t_stack	*normalized;
	size_t	index;
	size_t	i;

	normalized = ps_stack_init(stack->size);
	if (normalized)
	{
		i = 0;
		while (i < stack->size)
		{
			index = ps_fabricate_index(stack, stack->values[i]);
			ps_stack_r_push(normalized, index);
			i++;
		}
	}
	ps_stack_free(&stack);
	return (normalized);
}
