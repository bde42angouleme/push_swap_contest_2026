/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_kroussar_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:04:24 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:05:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/sort.h>

t_list	*ps_kroussar_sort(t_stack *a, t_stack *b)
{
	t_list	*list;

	list = NULL;
	ps_stack_free(&a);
	ps_stack_free(&b);
	return (list);
}
