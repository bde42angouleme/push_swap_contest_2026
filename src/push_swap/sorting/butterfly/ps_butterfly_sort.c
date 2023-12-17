/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:46:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 22:44:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ps/sort.h>

t_list	*ps_butterfly_stage1(t_stack *a, t_stack *b, size_t n_boxes,
			size_t n_per_boxes);
t_list	*ps_butterfly_stage2(t_stack *a, t_stack *b);

static t_list	*ps_butterfly_n_item(t_stack *a, t_stack *b, size_t n_per_boxes)
{
	t_list	*list;
	size_t	n_boxes;

	n_boxes = a->size / n_per_boxes;
	if (n_boxes * n_per_boxes < a->size)
		n_boxes++;
	list = ps_butterfly_stage1(a, b, n_boxes, n_per_boxes);
	if (list)
		ft_lst_add(&list, ps_butterfly_stage2(a, b));
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}

static size_t	ps_linear_interpolate_start(size_t size)
{
	return ((size_t)(0.06 * ((float)size) + 9));
}

static size_t	ps_linear_interpolate_end(size_t size)
{
	size_t	start;
	size_t	range;

	start = ps_linear_interpolate_start(size);
	range = ((size_t)(0.03 * ((float)size) + 32));
	return (start + range);
}

t_list	*ps_butterfly_sort(t_stack *a, t_stack *b)
{
	t_list	*list;
	t_list	*tmp;
	size_t	n_per;

	n_per = ps_linear_interpolate_start(a->size);
	if (n_per == 0)
		n_per = 1;
	list = NULL;
	while (n_per <= ps_linear_interpolate_end(a->size))
	{
		tmp = ps_butterfly_n_item(ps_stack_clone(a), ps_stack_clone(b), n_per);
		if (!tmp)
			return (NULL);
		if (!list || ft_lst_size(tmp) < ft_lst_size(list))
		{
			ft_lst_free(&list, NULL);
			list = tmp;
		}
		else
			ft_lst_free(&tmp, NULL);
		n_per++;
	}
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}
