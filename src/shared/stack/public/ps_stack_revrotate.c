/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_revrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:22:32 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:38:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

void	ps_stack_revrotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	ps_stack_r_push(stack, ps_stack_r_remove(stack));
}
