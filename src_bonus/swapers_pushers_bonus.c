/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_pushers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:18:10 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 20:38:48 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

//swap 2 first elements in stack a
void	sa(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	if (!(*stack))
		return ;
	tmp = *stack;
	if (!tmp->previous && !tmp->next)
		return ;
	tmp2 = (*stack)->next;
	tmp3 = tmp2->next;
	tmp2->previous = NULL;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp->previous = tmp2;
	*stack = tmp2;
	if (tmp3)
		tmp3->previous = tmp;
}

//swap 2 first elements in stack b
void	sb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	if (!(*stack))
		return ;
	tmp = *stack;
	if (!tmp->previous && !tmp->next)
		return ;
	tmp2 = (*stack)->next;
	tmp3 = tmp2->next;
	tmp2->previous = NULL;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp->previous = tmp2;
	*stack = tmp2;
	if (tmp3)
		tmp3->previous = tmp;
}

//sa + sb
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

//put top b in top a
void	pa(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		(*src)->previous = NULL;
		(*dest)->next = NULL;
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	tmp->next = *dest;
	(*dest)->previous = tmp;
	*dest = tmp;
	(*dest)->previous = NULL;
}

//put top a in top b
void	pb(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		(*src)->previous = NULL;
		(*dest)->next = NULL;
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	tmp->next = *dest;
	(*dest)->previous = tmp;
	*dest = tmp;
	(*dest)->previous = NULL;
}
