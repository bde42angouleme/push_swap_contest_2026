/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:28:23 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 09:52:10 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>
#include <ps/sort.h>
#include <ft/print.h>

static void	ps_wrap_exec(t_insn insn, t_stack *a, t_stack *b, t_list **feedback)
{
	ps_insn_exec(insn, a, b);
	ft_lst_tadd(feedback, (char *) ps_insn_name(insn));
}

static t_list	*ps_sort_size3(t_stack *a)
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

static t_list	*ps_sort_size5(t_stack *a, t_stack *b)
{
	t_list	*list;
	size_t	original_size;
	size_t	index;
	float	middle;

	list = NULL;
	original_size = a->size;
	while (a->size > 3)
	{
		middle = ((float)a->size) / 2. + .5;
		index = a->size - ps_stack_min_i(a) - 1;
		if (index < (size_t)middle)
			while (index-- > 0)
				ps_wrap_exec(RA, a, NULL, &list);
		else
			while (index++ < a->size)
				ps_wrap_exec(RRA, a, NULL, &list);
		ps_wrap_exec(PB, a, b, &list);
	}
	ft_lst_add(&list, ps_sort_size3(a));
	ps_wrap_exec(PA, a, b, &list);
	if (original_size == 5)
		ps_wrap_exec(PA, a, b, &list);
	return (list);
}

t_list	*ps_sort_smol(t_stack *a, t_stack *b)
{
	t_list	*list;

	list = NULL;
	if (a->size == 2)
	{
		if (a->values[1] > a->values[0])
			ps_wrap_exec(SA, a, b, &list);
	}
	else if (a->size == 3)
		list = ps_sort_size3(a);
	else if (a->size <= 5)
		list = ps_sort_size5(a, b);
	return (list);
}
