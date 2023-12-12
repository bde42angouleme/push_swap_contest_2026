/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:26:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 18:44:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>
#include <stdlib.h>

static t_list	*ps_sort0(t_stack *a, t_stack *b)
{
	static t_sorting_algorithm	algos[] = {
		ps_butterfly_sort,
		ps_turk_sort,
		ps_kroussar_sort,
		NULL
	};
	size_t						index;
	t_list						*final_list;
	t_list						*tmp_list;

	index = 0;
	final_list = NULL;
	while (algos[index])
	{
		tmp_list = algos[index](ps_stack_clone(a), ps_stack_clone(b));
		if (!final_list || ft_lstsize(tmp_list) < ft_lstsize(final_list))
		{
			ft_lstfree(&final_list, free);
			final_list = tmp_list;
		}
		else
			ft_lstfree(&tmp_list, free);
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
