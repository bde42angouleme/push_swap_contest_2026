/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:18:21 by nredouan          #+#    #+#             */
/*   Updated: 2026/01/05 13:30:13 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_algorithm(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	if (nbr == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, 0);
	}
	else if (nbr == 3)
		sort_three(stack_a);
	else
	{
		write_index((*stack_a), nbr);
		sort(stack_a, stack_b);
	}
	ft_lstfree(*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		nbr;

	stack_a = NULL;
	stack_b = NULL;
	error_check(argc, argv);
	nbr = parsing(argc, argv, &stack_a);
	if (!stack_a || !dup_check(stack_a) || nbr <= 1)
	{
		if (stack_a)
			ft_lstfree(stack_a);
		if (nbr <= 1)
			return (0);
		ft_error();
	}
	if (verif_order(stack_a))
	{
		ft_lstfree(stack_a);
		exit(1);
	}
	sort_algorithm(&stack_a, &stack_b, nbr);
}
