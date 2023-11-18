/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_r_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:11:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:14:41 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

void	ps_stack_r_push(t_stack *stack, int value)
{
	if (stack->size == stack->capacity)
		ps_stack_resize(stack, stack->capacity + 12);
	stack->values[stack->size] = value;
	stack->size++;
}
