/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_clone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:54:09 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 19:56:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

t_stack	*ps_stack_clone(t_stack *stack)
{
	t_stack	*new;
	size_t	i;

	new = ps_stack_init(stack->size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		ps_stack_r_push(new, stack->values[i]);
		i++;
	}
	return (new);
}
