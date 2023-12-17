/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:44:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 10:05:28 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <ps/optimize.h>

static void	ps_optimize_nullify(
		t_list **list,
		char *insn_do,
		char *insn_undo
) {
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*to_remove1;
	t_list	*to_remove2;

	tmp = *list;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (!ft_strcmp(tmp->content, insn_do)
			&& !ft_strcmp(tmp2->content, insn_undo))
		{
			to_remove1 = tmp;
			to_remove2 = tmp2;
			tmp = tmp2->next;
			tmp2 = NULL;
			if (tmp)
				tmp2 = tmp->next;
			ft_lst_remove(list, to_remove1, NULL);
			ft_lst_remove(list, to_remove2, NULL);
			continue ;
		}
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
}

static void	ps_optimize_pairs(
		t_list **list,
		char *insn_a,
		char *insn_b,
		char *insn_both
) {
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (!ft_strcmp(tmp->content, insn_a)
			&& !ft_strcmp(tmp2->content, insn_b))
		{
			tmp->content = insn_both;
			tmp->next = tmp2->next;
			ft_lst_delete(tmp2, NULL);
			tmp2 = tmp->next;
		}
		else
		{
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
}

static void	ps_optimize_all_pairs(t_list **list)
{
	ps_optimize_pairs(list, "sa", "sb", "ss");
	ps_optimize_pairs(list, "sb", "sa", "ss");
	ps_optimize_pairs(list, "ra", "rb", "rr");
	ps_optimize_pairs(list, "rb", "ra", "rr");
	ps_optimize_pairs(list, "rra", "rrb", "rrr");
	ps_optimize_pairs(list, "rrb", "rra", "rrr");
}

static void	ps_optimize_all_nullify(t_list **list)
{
	ps_optimize_nullify(list, "pa", "pb");
	ps_optimize_nullify(list, "pb", "pa");
	ps_optimize_nullify(list, "ra", "rra");
	ps_optimize_nullify(list, "rra", "ra");
	ps_optimize_nullify(list, "rb", "rrb");
	ps_optimize_nullify(list, "rrb", "rb");
	ps_optimize_nullify(list, "rr", "rrr");
	ps_optimize_nullify(list, "rrr", "rr");
	ps_optimize_nullify(list, "sa", "sa");
	ps_optimize_nullify(list, "sb", "sb");
	ps_optimize_nullify(list, "ss", "ss");
}

void	ps_optimize(t_list **list)
{
	size_t	old_size;
	size_t	new_size;

	old_size = ft_lst_size(*list);
	while (1)
	{
		ps_optimize_all_pairs(list);
		ps_optimize_all_nullify(list);
		new_size = ft_lst_size(*list);
		if (old_size != new_size)
			old_size = new_size;
		else
			break ;
	}
}
