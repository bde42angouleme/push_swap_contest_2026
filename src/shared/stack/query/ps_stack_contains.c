/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_contains.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:10 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 02:50:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

int	ps_stack_contains(t_stack *stack, int value)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] == value)
			return (1);
		i++;
	}
	return (0);
}
