/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_max_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:00:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:01:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>
#include <limits.h>

size_t	ps_stack_max_i(t_stack *stack)
{
	size_t	i;
	size_t	max_i;
	int		max;

	i = 0;
	max_i = 0;
	max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->values[i] > max)
		{
			max = stack->values[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}
