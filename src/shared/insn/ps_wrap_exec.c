/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_wrap_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:32:51 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 10:33:11 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>

void	ps_wrap_exec(t_insn insn, t_stack *a, t_stack *b, t_list **feedback)
{
	ps_insn_exec(insn, a, b);
	if (feedback)
		ft_lst_tadd(feedback, (char *) ps_insn_name(insn));
}
