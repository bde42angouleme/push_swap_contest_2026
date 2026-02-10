/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:20:58 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/20 17:01:58 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *array, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[end]);
	return (i + 1);
}

static int	*stack_dup(t_stack *stack)
{
	int		i;
	int		*array;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	array = malloc(sizeof(int) * ft_lstsize_stack(stack));
	if (!array)
		return (NULL);
	while (tmp->next)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	array[i] = tmp->value;
	return (array);
}

static void	quicksort(int *array, int start, int end)
{
	int	p_index;

	if (start < end)
	{
		p_index = partition(array, start, end);
		quicksort(array, start, p_index - 1);
		quicksort(array, p_index + 1, end);
	}
}

void	write_index(t_stack *stack_a, int nbr)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	i = 0;
	tmp = stack_a;
	array = stack_dup(stack_a);
	quicksort(array, 0, nbr - 1);
	tmp = stack_a;
	while (tmp)
	{
		while (tmp->value != array[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 0;
	}
	free(array);
}
