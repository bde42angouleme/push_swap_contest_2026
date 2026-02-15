/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:31:38 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/15 14:06:23 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_best(t_lis *lis, int n)
{
	int	i;
	int	best;

	i = 1;
	best = 0;
	while (i < n)
	{
		if (lis->dp[i] > lis->dp[best])
			best = i;
		i++;
	}
	return (best);
}

static void	build_lis(t_stack *map, t_lis *lis, int n)
{
	int			value;
	int			best;

	best = lis->best_lis[INDEX_BV];
	while (best != -1)
	{
		value = map->tab[(lis->best_lis[IDX] + best) % n];
		lis->lis[value] = 1;
		lis->size_lis++;
		best = lis->prev[best];
	}
}

static void	build_dp_prev_from_zero(t_stack *map, t_lis *lis, int n, int index)
{
	int			i;
	int			j;
	int			value_i;
	int			value_j;

	i = 1;
	while (i < n)
	{
		value_i = map->tab[(index + i) % n];
		j = 0;
		while (j < i)
		{
			value_j = map->tab[(index + j) % n];
			if (value_j < value_i && (lis->dp[j] + 1) > lis->dp[i])
			{
				lis->dp[i] = lis->dp[j] + 1;
				lis->prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static void	test_lis(t_lis *lis, t_stack *map)
{
	int	i;

	lis->best_lis[BEST_VALUE] = -1;
	lis->best_lis[IDX] = 0;
	lis->best_lis[INDEX_BV] = 0;
	i = 0;
	while (i < (int)map->size)
	{
		init_dp_prev(lis, (int)map->size);
		build_dp_prev_from_zero(map, lis, (int)map->size, i);
		lis->current_lis[INDEX_BV] = find_best(lis, (int)map->size);
		lis->current_lis[BEST_VALUE] = lis->dp[lis->current_lis[INDEX_BV]];
		lis->current_lis[IDX] = i;
		if (lis->current_lis[BEST_VALUE] > lis->best_lis[BEST_VALUE])
		{
			lis->best_lis[IDX] = lis->current_lis[IDX];
			lis->best_lis[INDEX_BV] = lis->current_lis[INDEX_BV];
			lis->best_lis[BEST_VALUE] = lis->current_lis[BEST_VALUE];
		}
		i++;
	}
	init_dp_prev(lis, (int)map->size);
	build_dp_prev_from_zero(map, lis, (int)map->size, lis->best_lis[IDX]);
}

int	find_best_lis(t_lis *lis, t_stack *map)
{
	lis->dp = ft_calloc(map->size, sizeof(int));
	lis->prev = ft_calloc(map->size, sizeof(int));
	lis->lis = ft_calloc(map->size, sizeof(int));
	if (!lis->dp || !lis->prev || !lis->lis)
	{
		free(lis->dp);
		free(lis->prev);
		free(lis->lis);
		return (ERROR);
	}
	test_lis(lis, map);
	build_lis(map, lis, (int)map->size);
	free(lis->dp);
	lis->dp = NULL;
	free(lis->prev);
	lis->prev = NULL;
	return (0);
}
