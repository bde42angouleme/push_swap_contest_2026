/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:36:26 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:37:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

void	ps_stack_push(t_stack *stack, t_stack *other)
{
	if (stack->size == 0)
		return ;
	ps_stack_r_push(other, ps_stack_r_pop(stack));
}
