/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_r_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:18:41 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:56:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

int	ps_stack_r_pop(t_stack *stack)
{
	int	value;

	if (stack->size == 0)
		return (0);
	value = ps_stack_top(stack);
	stack->size--;
	return (value);
}
