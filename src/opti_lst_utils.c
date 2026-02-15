/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:30:46 by rcompain          #+#    #+#             */
/*   Updated: 2026/02/13 11:09:43 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Count the number of rbs, then the number of ras. This also works for rrbs 
 * and rras.
 */
int	*count_rr_or_rrr(t_list *curent, char *str1, char *str2, int size)
{
	t_list	*tmp;
	int		*count;

	count = ft_calloc(3, sizeof(int));
	if (!count)
		return (NULL);
	tmp = curent;
	while (tmp && (ft_strncmp((char *)tmp->content, str1, size) == 0))
	{
		count[0]++;
		tmp = tmp->next;
	}
	while (tmp && (ft_strncmp((char *)tmp->content, str2, size) == 0))
	{
		count[1]++;
		tmp = tmp->next;
	}
	return (count);
}

/**
 * Adds a space to the first character of the content of a list.
 */
void	put_space(t_list *curent, int i, int flag)
{
	if (flag == ERROR)
		return ;
	while (i > 0 && curent)
	{
		((char *)curent->content)[0] = ' ';
		curent = curent->next;
		i--;
	}
}
