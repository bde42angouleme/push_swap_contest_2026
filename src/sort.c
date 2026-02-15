/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/15 14:17:18 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * This function rotates the stack to put the minimum at the top.
 **/
static int	rotate_min_to_top(t_stack *map, t_list **lst, int flag)
{
	if (flag == ERROR)
		return (flag);
	if (map->size <= 1)
		return (0);
	if (map->tab[0] > (int)map->size / 2)
	{
		while (map->tab[0] != 0 && flag == 0)
			flag = new_cmd(lst, map, NULL, ra);
	}
	else
	{
		while (map->tab[0] != 0 && flag == 0)
			flag = new_cmd(lst, map, NULL, rra);
	}
	return (flag);
}

/**
 * This function pushes a value from stack b to the stack map 
 * at its sorted position. It chooses the value with the lowest 
 * movement cost.
 **/
int	push_best_to_a(t_stack *map, t_stack *b, t_list **lst, int flag)
{
	int			mv;
	const int	*best = check_best_index(map, b);
	const int	value = b->tab[best[0]];

	if (!best || flag == ERROR)
		return (ERROR);
	mv = best[2];
	while ((best[1] == RA_RB || best[1] == RRA_RB)
		&& b->tab[0] != value && flag == 0)
	{
		flag = new_cmd(lst, b, NULL, rb);
		mv--;
	}
	while ((best[1] == RRA_RRB || best[1] == RA_RRB)
		&& b->tab[0] != value && flag == 0)
	{
		flag = new_cmd(lst, b, NULL, rrb);
		mv--;
	}
	while ((best[1] == RA_RB || best[1] == RA_RRB) && mv-- != 0 && flag == 0)
		flag = new_cmd(lst, map, NULL, ra);
	while ((best[1] == RRA_RRB || best[1] == RRA_RB) && mv-- != 0 && flag == 0)
		flag = new_cmd(lst, map, NULL, rra);
	free((int *)best);
	return (flag);
}

static int	check_add_lis(t_stack *map, t_stack *b, t_list **lst, t_lis *lis)
{
	int	value;
	int	flag;

	if (lis->lis[map->tab[0]] == 1)
	{
		value = check_previous_index_lis(map, lis);
		if (value != -1)
		{
			if (map->tab[1] < map->tab[0] && map->tab[1] > value)
			{
				flag = new_cmd(lst, map, NULL, sa);
				lis->lis[map->tab[0]] = 1;
				lis->size_lis++;
				if (b->size > 2 && b->tab[0] < b->tab[1])
					flag = new_cmd(lst, map, b, sb);
			}
		}
	}
	flag = new_cmd(lst, map, NULL, ra);
	return (flag);
}

static int	push_nt_lis_to_b(t_stack *map, t_stack *b, t_list **lst, t_lis *lis)
{
	int			flag;
	size_t		size;
	int			i;
	static int	chunk = -1;

	flag = 0;
	chunk += lis->n;
	if (map->size == lis->size_lis)
		return (0);
	size = map->size;
	i = -1;
	while (++i < (int)size && flag == 0)
	{
		if (lis->lis[map->tab[0]] == 1 || map->tab[0] > chunk)
			flag = check_add_lis(map, b, lst, lis);
		else
		{
			flag = new_cmd(lst, map, b, pb);
			if (flag == 0 && b->size > 1 && b->tab[0] < chunk - (lis->n / 2))
				flag = new_cmd(lst, b, NULL, rb);
		}
	}
	flag = push_nt_lis_to_b(map, b, lst, lis);
	return (flag);
}

/**
 * This function checks if the number of values is less than 6 in order 
 * to execute an optimized algorithm. If not, it executes the main algorithm.
 **/
t_list	*algo_sort(t_stack *map, t_stack *b, int flag)
{
	t_list		*lst;
	t_lis		lis;

	if (stack_sorted(map) == TRUE)
		return (NULL);
	lst = NULL;
	ft_memset(&lis, 0, sizeof(t_lis));
	if (map->size <= 5)
		flag = tiny_sort(map, b, &lst);
	else
	{
		lis.n = map->size / N_CHUNK;
		flag = find_best_lis(&lis, map);
		if (flag != ERROR)
			flag = push_nt_lis_to_b(map, b, &lst, &lis);
		free(lis.lis);
	}
	while (b->size > 0 && flag == 0)
	{
		flag = push_best_to_a(map, b, &lst, flag);
		flag = new_cmd(&lst, map, b, pa);
	}
	if (flag == ERROR || rotate_min_to_top(map, &lst, flag) == ERROR)
		return (NULL);
	return (lst);
}
