/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_r_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:13:16 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:43:59 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

void	ps_stack_r_insert(t_stack *stack, int value)
{
	size_t	i;

	if (stack->size == stack->capacity)
		ps_stack_resize(stack, stack->capacity + 12);
	i = stack->size;
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = value;
	stack->size++;
}
