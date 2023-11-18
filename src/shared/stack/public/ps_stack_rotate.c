/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:22:14 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:39:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

void	ps_stack_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	ps_stack_r_insert(stack, ps_stack_r_pop(stack));
}
