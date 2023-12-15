/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:26:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 11:14:17 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/error.h>
#include <ps/sort.h>
#include <stdlib.h>

static t_list	*ps_sort0(t_stack *a, t_stack *b)
{
	static t_sorting_algorithm	algos[] = {ps_butterfly_sort, ps_turk_sort,
		ps_kroussar_sort, NULL};
	size_t						index;
	t_list						*final_list;
	t_list						*tmp_list;

	index = 0;
	final_list = NULL;
	while (algos[index])
	{
		tmp_list = algos[index](ps_stack_clone(a), ps_stack_clone(b));
		if (!tmp_list)
			index++;
		if (!tmp_list)
			continue ;
		if (!final_list || ft_lst_size(tmp_list) < ft_lst_size(final_list))
		{
			ft_lst_free(&final_list, NULL);
			final_list = tmp_list;
		}
		else
			ft_lst_free(&tmp_list, NULL);
		index++;
	}
	return (final_list);
}

t_list	*ps_sort(t_stack *a, t_stack *b)
{
	if (ps_stack_is_sorted(a))
		return (NULL);
	if (a->size <= 5)
		return (ps_sort_smol(a, b));
	return (ps_sort0(a, b));
}
