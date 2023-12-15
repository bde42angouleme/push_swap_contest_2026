/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:25:26 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 20:47:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <ft/data/list.h>
# include <ps/insn.h>
# include <ps/stack.h>

typedef t_list	*(*t_sorting_algorithm)(t_stack *, t_stack *);

t_list	*ps_sort(t_stack *a, t_stack *b);
t_list	*ps_sort_smol(t_stack *a, t_stack *b);

t_list	*ps_butterfly_sort(t_stack *a, t_stack *b);
t_list	*ps_turk_sort(t_stack *a, t_stack *b);
t_list	*ps_kroussar_sort(t_stack *a, t_stack *b);

t_stack	*ps_stack_normalize(t_stack *stack);

void	ps_fetch(t_stack *stack, size_t index, t_list **list, t_insn insns[2]);
size_t	ps_fetch_insns(t_stack *stack, size_t index);

#endif
