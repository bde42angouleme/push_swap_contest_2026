/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:30:37 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/15 14:10:39 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Removes lists with a space as the first character.
 */
static void	purify_space(t_list **lst, t_list *curent)
{
	t_list	*prev;

	prev = NULL;
	while (curent && curent->next)
	{
		if (((char *)curent->content)[0] == ' ')
		{
			if (!prev)
				*lst = curent->next;
			else
				prev->next = curent->next;
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
 * Replace rrb with rrr according to the number of consecutive rrb rra  
 * sequences.
 */
static void	replace_rrr(t_list *curent, int i, int *flag)
{
	int		*count;

	while (*flag == 0 && curent && curent->next)
	{
		if (ft_strncmp(curent->content, "rrb", 3) == 0)
		{
			count = count_rr_or_rrr(curent, "rrb", "rra", 3);
			if (!count)
				*flag = ERROR;
			i = 0;
			while (*flag == 0 && ft_strncmp(curent->content, "rrb", 3) == 0)
			{
				if (count[0] > i && count[1] > i)
				{
					((char *)curent->content)[2] = 'r';
					i++;
				}
				curent = curent->next;
			}
			put_space(curent, i, *flag);
			free_and_null(count);
		}
		else
			curent = curent->next;
	}
}

/**
 * Replace rb with rr according to the number of consecutive rb ra sequences.
 */
static void	replace_rr(t_list *curent, int i, int *flag)
{
	int		*count;

	while (*flag == 0 && curent && curent->next)
	{
		if (ft_strncmp(curent->content, "rb", 2) == 0)
		{
			count = count_rr_or_rrr(curent, "rb", "ra", 2);
			if (!count)
				*flag = ERROR;
			i = 0;
			while (*flag == 0 && ft_strncmp(curent->content, "rb", 2) == 0)
			{
				if (count[0] > i && count[1] > i)
				{
					((char *)curent->content)[1] = 'r';
					i++;
				}
				curent = curent->next;
			}
			put_space(curent, i, *flag);
			free_and_null(count);
		}
		else
			curent = curent->next;
	}
}

static void	replace_ss(t_list *curent, int i, int *flag)
{
	int		*count;

	while (*flag == 0 && curent && curent->next)
	{
		if (ft_strncmp(curent->content, "sa", 2) == 0)
		{
			count = count_rr_or_rrr(curent, "sa", "sb", 2);
			if (!count)
				*flag = ERROR;
			i = 0;
			while (*flag == 0 && ft_strncmp(curent->content, "sa", 2) == 0)
			{
				if (count[0] > i && count[1] > i)
				{
					((char *)curent->content)[1] = 's';
					i++;
				}
				curent = curent->next;
			}
			put_space(curent, i, *flag);
			free_and_null(count);
		}
		else
			curent = curent->next;
	}
}

/**
 * This Fonction call diferrents optimisations fonctions.
 */
int	opti(t_list **lst)
{
	int	flag;
	int	i;

	flag = 0;
	if (lst)
	{
		i = -1;
		while (++i < N_CHUNK)
		{
			del_pa_pb(lst, *lst);
			del_ra_rra(lst, *lst);
			del_rb_rrb(lst, *lst);
		}
		replace_ss(*lst, 0, &flag);
		if (flag == ERROR)
			return (ERROR);
		replace_rr(*lst, 0, &flag);
		if (flag == ERROR)
			return (ERROR);
		replace_rrr(*lst, 0, &flag);
		if (flag == ERROR)
			return (ERROR);
		purify_space(lst, *lst);
	}
	return (0);
}
