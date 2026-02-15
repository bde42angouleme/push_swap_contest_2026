/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_lst_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:32:49 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/15 14:10:05 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	del_rb_rrb(t_list **lst, t_list *curent)
{
	t_list	*prev;

	prev = NULL;
	while (curent && curent->next)
	{
		if ((ft_strncmp(curent->content, "rb", 2) == 0
				&& ft_strncmp(curent->next->content, "rrb", 3) == 0)
			|| (ft_strncmp(curent->content, "rrb", 3) == 0
				&& ft_strncmp(curent->next->content, "rb", 2) == 0))
		{
			if (!prev)
				*lst = curent->next->next;
			else
				prev->next = curent->next->next;
			ft_lstdelone(curent->next, free);
			ft_lstdelone(curent, free);
			curent = *lst;
			prev = NULL;
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}

void	del_ra_rra(t_list **lst, t_list *curent)
{
	t_list	*prev;

	prev = NULL;
	while (curent && curent->next)
	{
		if ((ft_strncmp(curent->content, "ra", 2) == 0
				&& ft_strncmp(curent->next->content, "rra", 3) == 0)
			|| (ft_strncmp(curent->content, "rra", 3) == 0
				&& ft_strncmp(curent->next->content, "ra", 2) == 0))
		{
			if (!prev)
				*lst = curent->next->next;
			else
				prev->next = curent->next->next;
			ft_lstdelone(curent->next, free);
			ft_lstdelone(curent, free);
			curent = *lst;
			prev = NULL;
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}

/**
 * Removes lists reproducing the sequence pb pa.
 */
void	del_pa_pb(t_list **lst, t_list *curent)
{
	t_list	*prev;

	prev = NULL;
	while (curent && curent->next)
	{
		if (ft_strncmp(curent->content, "pb", 2) == 0
			&& ft_strncmp(curent->next->content, "pa", 2) == 0)
		{
			if (!prev)
				*lst = curent->next->next;
			else
				prev->next = curent->next->next;
			ft_lstdelone(curent->next, free);
			ft_lstdelone(curent, free);
			curent = *lst;
			prev = NULL;
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}
