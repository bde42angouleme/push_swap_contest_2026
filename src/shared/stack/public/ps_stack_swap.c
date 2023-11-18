/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:21:37 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:57:37 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

void	ps_stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = ps_stack_top(stack);
	stack->values[stack->size - 1] = stack->values[stack->size - 2];
	stack->values[stack->size - 2] = tmp;
}
