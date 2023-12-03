/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:28:23 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/02 22:47:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>
#include <ps/sort.h>

static void	ps_sort_size3(t_stack *a)
{

}

void	ps_sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		if (a->values[0] < a->values[1])
			ps_insn_exec(SA, a, b);
	if (a->size == 3)
		ps_sort_size3(a);
	if (a->size == 4)
	{
	}
	if (a->size == 5)
	{
	}
}
