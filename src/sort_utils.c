/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:59:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/15 14:05:32 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_dp_prev(t_lis *lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis->dp[i] = 1;
		lis->prev[i] = -1;
		i++;
	}
}

int	check_previous_index_lis(t_stack *map, t_lis *lis)
{
	int	i;

	i = map->tab[0] - 1;
	while (i >= 0)
	{
		if (lis->lis[i] == 1)
			return (i);
		i--;
	}
	return (-1);
}
