/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:05:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:05:19 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

t_list	*ps_turk_sort(t_stack *a, t_stack *b)
{
	t_list	*list;

	list = NULL;
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}
