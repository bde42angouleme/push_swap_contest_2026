/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:52:44 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 10:53:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

int	ps_stack_index(t_stack *stack, int value)
{
	size_t	index;

	index = 0;
	while (index < stack->size)
	{
		if (stack->values[index] == value)
			return (index);
		index++;
	}
	return (-1);
}
