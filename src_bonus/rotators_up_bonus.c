/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotators_up_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:32:13 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 20:38:20 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

//rotate up all elements of a (first become last)
void	ra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return ;
	tmp = *stack;
	tmp2 = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	if (!tmp->previous && !tmp->next)
		return ;
	tmp->next = *stack;
	(*stack)->next->previous = NULL;
	(*stack)->previous = tmp;
	(*stack)->next = NULL;
	*stack = tmp2;
}

//rotate up all elements of b (first become last)
void	rb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return ;
	tmp = *stack;
	tmp2 = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	if (!tmp->previous && !tmp->next)
		return ;
	tmp->next = *stack;
	(*stack)->next->previous = NULL;
	(*stack)->previous = tmp;
	(*stack)->next = NULL;
	*stack = tmp2;
}

//rotate both stacks
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
