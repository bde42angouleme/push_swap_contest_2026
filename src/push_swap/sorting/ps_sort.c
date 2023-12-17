/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:26:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 01:57:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/error.h>
#include <ps/optimize.h>
#include <ps/sort.h>
#include <stdlib.h>

static t_list	*ps_sort0(t_stack *a, t_stack *b)
{
	static t_sorting_algorithm	algos[] = {ps_butterfly_sort, NULL};
	size_t						index;
	t_list						*final_list;
	t_list						*tmp_list;

	index = 0;
	final_list = NULL;
	while (algos[index++])
	{
		tmp_list = algos[index - 1](ps_stack_clone(a), ps_stack_clone(b));
		if (!tmp_list)
			continue ;
		ps_optimize(&tmp_list);
		if (!final_list || ft_lst_size(tmp_list) < ft_lst_size(final_list))
		{
			ft_lst_free(&final_list, NULL);
			final_list = tmp_list;
		}
		else
			ft_lst_free(&tmp_list, NULL);
	}
	return (final_list);
}

t_list	*ps_sort(t_stack *a, t_stack *b)
{
	t_list	*list;
	t_stack	*tmp;

	list = NULL;
	if (!ps_stack_is_sorted(a))
	{
		if (a->size <= 5)
			list = ps_sort_smol(a, b);
		else
		{
			tmp = ps_stack_normalize(a);
			if (!tmp)
				return (NULL);
			list = ps_sort0(tmp, b);
			ps_stack_free(&tmp);
			return (list);
		}
	}
	ps_stack_free(&a);
	return (list);
}
