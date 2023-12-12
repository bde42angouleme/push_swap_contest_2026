/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:58:03 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:01:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>
#include <limits.h>

int	ps_stack_min(t_stack *stack)
{
	size_t	i;
	int		min;

	min = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < min)
			min = stack->values[i];
		i++;
	}
	return (min);
}
