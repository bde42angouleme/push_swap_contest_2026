/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insn_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:58:37 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/02 22:04:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/insn.h>

bool	*ps_insn_should_print(void)
{
	static bool	should_print = false;

	return (&should_print);
}

void	ps_insn_set_should_print(bool should_print)
{
	*ps_insn_should_print() = should_print;
}
