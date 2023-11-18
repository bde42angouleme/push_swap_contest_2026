/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:40:04 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:41:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <ps/stack.h>

void	ps_stack_print(t_stack *stack)
{
	int	i;

	ft_printf("Stack (size: %d, capacity: %d)\n", stack->size, stack->capacity);
	i = stack->size - 1;
	while (i >= 0)
	{
		ft_printf("%d\n", stack->values[i]);
		i--;
	}
}
