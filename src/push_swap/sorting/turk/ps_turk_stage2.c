/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_stage2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:05:39 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/16 00:04:50 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

t_list	*ps_sort_size3(t_stack *a);

void	ps_turk_stage2(t_stack *a, t_stack *b, t_list **list)
{
	ft_lst_add(list, ps_sort_size3(a));
	while (b->size > 0)
	{
		if (a->values[0] == b->values[b->size - 1] + 1)
			ps_wrap_exec(RRA, a, b, list);
		ps_wrap_exec(PB, a, b, list);
		if (a->values[a->size - 1] > a->values[a->size - 2])
			ps_wrap_exec(SA, a, b, list);
	}
}
