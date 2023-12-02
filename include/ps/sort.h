/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:25:26 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/24 01:28:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <ps/stack.h>

void	ps_sort(t_stack *a, t_stack *b);

void	ps_sort_small(t_stack *a, t_stack *b);
void	ps_sort_big(t_stack *a, t_stack *b);

#endif
