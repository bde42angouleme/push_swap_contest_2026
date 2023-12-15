/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:46:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 12:31:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ps/sort.h>

t_list	*ps_butterfly_stage1(t_stack *a, t_stack *b, size_t n_boxes,
			size_t n_per_boxes);
t_list	*ps_butterfly_stage2(t_stack *a, t_stack *b);

static size_t	ps_fabricate_index(t_stack *stack, int number)
{
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < number)
			index++;
		i++;
	}
	return (index);
}

static t_stack	*ps_normalize(t_stack *stack)
{
	t_stack	*normalized;
	size_t	index;
	size_t	i;

	normalized = ps_stack_init(stack->size);
	if (!normalized)
		ps_stack_free(&stack);
	if (!normalized)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		index = ps_fabricate_index(stack, stack->values[i]);
		ps_stack_r_push(normalized, index);
		i++;
	}
	ps_stack_free(&stack);
	return (normalized);
}

t_list	*ps_butterfly_sort(t_stack *a, t_stack *b)
{
	t_list	*list;
	size_t	n_per_boxes;
	size_t	n_boxes;

	list = NULL;
	a = ps_normalize(a);
	if (a)
	{
		n_per_boxes = (size_t)(((float)ft_max(20, a->size)) * 0.055 + 14.5);
		n_boxes = a->size / n_per_boxes;
		if (n_boxes * n_per_boxes < a->size)
			n_boxes++;
		list = ps_butterfly_stage1(a, b, n_boxes, n_per_boxes);
		if (list)
			ft_lst_add(&list, ps_butterfly_stage2(a, b));
	}
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}
