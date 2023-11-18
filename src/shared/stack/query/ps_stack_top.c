/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:07:16 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:07:44 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

int	ps_stack_top(t_stack *stack)
{
	if (ps_stack_is_empty(stack))
		return (0);
	return (stack->values[stack->size - 1]);
}
