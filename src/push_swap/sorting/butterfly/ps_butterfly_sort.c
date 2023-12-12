/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:46:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:06:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

static t_stack	*ps_normalize(t_stack *stack)
{
	t_stack	*normalized;

	normalized = ps_stack_init(stack->size);
	if (!normalized)
		return (NULL);
	return (normalized);
}

t_list	*ps_butterfly_sort(t_stack *a, t_stack *b)
{
	t_list	*list;

	list = NULL;
	a = ps_normalize(a);
	if (a)
	{
	}
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}
