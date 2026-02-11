/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotators_down_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:20:08 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 20:37:54 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

//reverse rotate a (rotate down)
void	rra(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	if (!tmp->previous && !tmp->next)
		return ;
	if (tmp->previous)
	{
		tmp->previous->next = NULL;
		tmp->previous = NULL;
	}
	tmp->next = *stack;
	(*stack)->previous = tmp;
	(*stack) = tmp;
}

//reverse rotate b (rotate down)
void	rrb(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	if (!tmp->previous && !tmp->next)
		return ;
	if (tmp->previous)
	{
		tmp->previous->next = NULL;
		tmp->previous = NULL;
	}
	tmp->next = *stack;
	(*stack)->previous = tmp;
	(*stack) = tmp;
}

//reverse rotate both stacks
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
