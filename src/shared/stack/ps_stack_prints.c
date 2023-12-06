/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:11:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/06 21:11:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ft/print.h>
#include <ps/stack.h>

void	ps_stack_prints(t_stack *a, t_stack *b)
{
	size_t	max;

	ft_printf("Stack A\tStack B\n");
	ft_printf("-------\t-------\n");
	max = ft_max(a->size, b->size);
	while (max--)
	{
		if (a->size > max)
			ft_printf("%7d", a->values[max]);
		else
			ft_printf("%7c", ' ');
		if (b->size > max)
			ft_printf("\t%d", b->values[max]);
		ft_printf("\n");
	}
	ft_printf("-------\t-------\n");
}
