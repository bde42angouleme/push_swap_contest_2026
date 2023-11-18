/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:00:38 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:16:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/mem.h>
#include <ps/stack.h>
#include <stdlib.h>

void	ps_stack_resize(t_stack *stack, size_t new_size)
{
	int	*new_values;

	if (new_size < stack->capacity)
		return ;
	new_values = (int *)ft_calloc(new_size, sizeof(int));
	if (new_values == NULL)
		return ;
	if (stack->values)
		ft_memcpy(new_values, stack->values, stack->size * sizeof(int));
	if (stack->values)
		free(stack->values);
	stack->values = new_values;
	stack->capacity = new_size;
}
