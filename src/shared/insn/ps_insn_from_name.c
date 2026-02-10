/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insn_from_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:32:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 02:38:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <ps/insn.h>

t_insn	ps_insn_from_name(const char *name)
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
	size_t				i;

	i = 0;
	while (i < sizeof(insn_name) / sizeof(insn_name[0]))
	{
		if (!ft_strcmp(insn_name[i], name))
			return (i);
		i++;
	}
	return (NONE);
}
