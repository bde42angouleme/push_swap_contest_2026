/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:20:06 by nredouan          #+#    #+#             */
/*   Updated: 2026/01/08 16:11:11 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	verif_order(t_stack *stack)
{
	while (stack && stack->next && stack->value < stack->next->value)
	{
		if (stack->next)
			stack = stack->next;
		if (!stack->next)
			return (1);
	}
	return (0);
}
