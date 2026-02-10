/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_pushers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:18:10 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 20:40:48 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//swap 2 first elements in stack a
void	sa(t_stack **stack, int i)
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
	if (i == 0)
		ft_printf("sa\n");
}

//swap 2 first elements in stack b
void	sb(t_stack **stack, int i)
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
	if (i == 0)
		ft_printf("sb\n");
}

//sa + sb
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_printf("ss\n");
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
		ft_printf("pa\n");
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
	ft_printf("pa\n");
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
		ft_printf("pb\n");
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
	ft_printf("pb\n");
}
