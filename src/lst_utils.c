/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:55:49 by nredouan          #+#    #+#             */
/*   Updated: 2025/12/18 19:13:42 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_double_lstlast(t_stack *lst)
{
	t_stack	*last_lst;

	if (!lst)
		return (NULL);
	last_lst = lst;
	while (last_lst->next)
		last_lst = last_lst->next;
	return (last_lst);
}

t_stack	*ft_double_lstnew(long long int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->cost = 0;
	new->index = 0;
	new->ra = 0;
	new->rra = 0;
	new->rb = 0;
	new->rrb = 0;
	new->value = value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

int	ft_lstsize_stack(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstfree(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return ;
	while (lst)
	{
		tmp = tmp->next;
		free(lst);
		lst = tmp;
	}
}

void	new_node(char *splitter, t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = ft_double_lstlast(stack_a);
	tmp->next = ft_double_lstnew(ft_atoll(splitter));
	if (!tmp->next)
	{
		ft_lstfree(stack_a);
		return ;
	}
	tmp->next->previous = tmp;
}
