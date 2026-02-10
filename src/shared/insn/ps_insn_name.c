/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insn_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:14:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 02:36:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>

const char	*ps_insn_name(t_insn insn)
{
	static const char	*insn_name[] = {
	[NONE] = "none",
	[SA] = "sa",
	[SB] = "sb",
	[SS] = "ss",
	[PA] = "pa",
	[PB] = "pb",
	[RA] = "ra",
	[RB] = "rb",
	[RR] = "rr",
	[RRA] = "rra",
	[RRB] = "rrb",
	[RRR] = "rrr",
	};

	return (insn_name[insn]);
}
