/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:28:23 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 10:06:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>
#include <ps/optimize.h>
#include <ps/sort.h>

t_list	*ps_sort_size3(t_stack *a)
{
	t_list	*list;
	size_t	index;

	list = NULL;
	index = ps_stack_max_i(a);
	if (index == 2)
		ps_wrap_exec(RA, a, NULL, &list);
	else if (index == 1)
		ps_wrap_exec(RRA, a, NULL, &list);
	if (a->values[2] > a->values[1])
		ps_wrap_exec(SA, a, NULL, &list);
	return (list);
}

static t_list	*ps_sort_size5_lsd(t_stack *a, t_stack *b)
{
	t_list	*list;

	list = NULL;
	while (a->size > 3)
	{
		ps_fetch(a, ps_stack_min_i(a), &list, (t_insn[2]){RA, RRA});
		ps_wrap_exec(PB, a, b, &list);
	}
	ft_lst_add(&list, ps_sort_size3(a));
	while (b->size > 0)
		ps_wrap_exec(PA, a, b, &list);
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}

static t_list	*ps_sort_size5_hsd(t_stack *a, t_stack *b)
{
	t_list	*list;

	list = NULL;
	while (a->size > 3)
	{
		ps_fetch(a, ps_stack_max_i(a), &list, (t_insn[2]){RA, RRA});
		ps_wrap_exec(PB, a, b, &list);
	}
	ft_lst_add(&list, ps_sort_size3(a));
	while (b->size > 0)
	{
		ps_wrap_exec(PA, a, b, &list);
		ps_wrap_exec(RA, a, b, &list);
	}
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}

t_list	*ps_sort_smol(t_stack *a, t_stack *b)
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	if (a->size == 2 && a->values[1] > a->values[0])
		ps_wrap_exec(SA, a, b, &list);
	else if (a->size == 3)
		list = ps_sort_size3(a);
	else if (a->size == 4 || a->size == 5)
	{
		list = ps_sort_size5_lsd(ps_stack_clone(a), ps_stack_clone(b));
		tmp = ps_sort_size5_hsd(ps_stack_clone(a), ps_stack_clone(b));
		ps_optimize(&list);
		ps_optimize(&tmp);
		if (ft_lst_size(list) > ft_lst_size(tmp))
		{
			ft_lst_free(&list, NULL);
			list = tmp;
		}
		else
			ft_lst_free(&tmp, NULL);
	}
	return (list);
}
