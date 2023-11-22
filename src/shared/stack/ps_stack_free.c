/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:02:11 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 02:52:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>
#include <stdlib.h>

void	ps_stack_free(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free((*stack)->values);
	free(*stack);
	*stack = NULL;
}
