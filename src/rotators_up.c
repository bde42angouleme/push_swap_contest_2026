/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotators_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:32:13 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 20:40:31 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//rotate up all elements of a (first become last)
void	ra(t_stack **stack, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return ;
	tmp = *stack;
	if (!tmp->previous && !tmp->next)
		return ;
	tmp2 = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next->previous = NULL;
	(*stack)->previous = tmp;
	(*stack)->next = NULL;
	*stack = tmp2;
	if (i == 0)
		ft_printf("ra\n");
}

//rotate up all elements of b (first become last)
void	rb(t_stack **stack, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return ;
	tmp = *stack;
	if (!tmp->previous && !tmp->next)
		return ;
	tmp2 = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next->previous = NULL;
	(*stack)->previous = tmp;
	(*stack)->next = NULL;
	*stack = tmp2;
	if (i == 0)
		ft_printf("rb\n");
}

//rotate both stacks
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	ft_printf("rr\n");
}
