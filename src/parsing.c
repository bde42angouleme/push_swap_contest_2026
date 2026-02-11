/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:56:00 by nredouan          #+#    #+#             */
/*   Updated: 2026/01/20 16:07:48 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	value_check(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if ((tmp->value > 2147483647) || (tmp->value < -2147483648))
		{
			ft_lstfree(stack);
			ft_error();
		}
		tmp = tmp->next;
	}
}

static void	splitter_into_stack(char **splitter, t_stack **stack_a, int j)
{
	long long int	nbr;

	if (!splitter[j])
	{
		ft_lstfree(*stack_a);
		free_str(splitter);
		ft_error();
	}
	while (splitter[j])
	{
		if (!*stack_a)
		{
			nbr = ft_atoll(splitter[j]);
			*stack_a = ft_double_lstnew(nbr);
			if (!*stack_a)
				return ;
		}
		else
			new_node(splitter[j], *stack_a);
		j++;
	}
}

int	error_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (j != 0 && (argv[i][j] == '+' || argv[i][j] == '-')
				&& ft_isdigit(argv[i][j + 1]) && ft_isdigit(argv[i][j - 1]))
				ft_error();
			else if (argv[i][j] == ' ' || ft_isdigit(argv[i][j])
				|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '+' && ft_isdigit(argv[i][j + 1])))
				j++;
			else
				ft_error();
		}
		j = 0;
		i++;
	}
	return (1);
}

int	dup_check(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_a;
	tmp2 = stack_a->next;
	while (tmp)
	{
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		if (tmp)
			tmp2 = tmp->next;
	}
	return (1);
}

int	parsing(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*tmp;
	char	**splitter;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		splitter = ft_split(argv[i], ' ');
		if (!splitter)
			return (0);
		splitter_into_stack(splitter, stack_a, j);
		free_str(splitter);
		j = 0;
		i++;
	}
	value_check(*stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		tmp = tmp->next;
		j++;
	}
	return (j);
}
