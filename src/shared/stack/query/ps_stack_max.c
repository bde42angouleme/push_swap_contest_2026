/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:02:01 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:02:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>
#include <limits.h>

int	ps_stack_max(t_stack *stack)
{
	size_t	i;
	int		max;

	i = 0;
	max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->values[i] > max)
			max = stack->values[i];
		i++;
	}
	return (max);
}
