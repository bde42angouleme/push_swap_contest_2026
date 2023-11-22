/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insn_info_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:04:43 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 00:32:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>

void	ps_insn_exec(t_insn insn, t_stack *a, t_stack *b)
{
	int					i;
	static t_insn_info	insn_info_map[] = {
	{PA, ps_insn_pa},
	{PB, ps_insn_pb},
	{SA, ps_insn_sa},
	{SB, ps_insn_sb},
	{SS, ps_insn_ss},
	{RA, ps_insn_ra},
	{RB, ps_insn_rb},
	{RR, ps_insn_rr},
	{RRA, ps_insn_rra},
	{RRB, ps_insn_rrb},
	{RRR, ps_insn_rrr},
	{0, NULL}
	};

	i = 0;
	while (insn_info_map[i].f)
	{
		if (insn_info_map[i].insn == insn)
			insn_info_map[i].f(a, b);
		if (insn_info_map[i].insn == insn)
			return ;
		i++;
	}
}
