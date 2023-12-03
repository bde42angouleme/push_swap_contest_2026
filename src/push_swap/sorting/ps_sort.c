/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:26:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/02 21:50:38 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

void	ps_sort_small(t_stack *a, t_stack *b);

static void	ps_sort0(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

void	ps_sort(t_stack *a, t_stack *b)
{
	if (ps_stack_is_sorted(a))
		return ;
	if (a->size <= 5)
		ps_sort_small(a, b);
	else
		ps_sort0(a, b);
}
