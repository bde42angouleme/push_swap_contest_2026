/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_min_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:59:53 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:01:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>
#include <limits.h>

size_t	ps_stack_min_i(t_stack *stack)
{
	size_t	i;
	int		min;
	size_t	min_i;

	min = INT_MAX;
	min_i = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < min)
		{
			min = stack->values[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}
