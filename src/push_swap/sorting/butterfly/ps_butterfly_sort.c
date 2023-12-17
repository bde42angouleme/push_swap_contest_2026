/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:46:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 07:40:46 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ps/sort.h>
#include <ft/print.h>

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

t_list	*ps_butterfly_sort(t_stack *a, t_stack *b)
{
	t_list	*list;
	t_list	*tmp;
	size_t	n_per;

	n_per = a->size / 10;
	if (n_per == 0)
		n_per = 1;
	list = NULL;
	while (n_per <= (size_t)ft_min(a->size / 2, 90))
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
