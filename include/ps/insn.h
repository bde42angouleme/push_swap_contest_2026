/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insn.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:58:28 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 16:41:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSN_H
# define INSN_H

# include <ps/stack.h>
# include <stdbool.h>

typedef enum e_insn
{
	NONE = 0,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_insn;

typedef struct s_insn_info
{
	t_insn	insn;
	void	(*f)(t_stack *, t_stack *);
}	t_insn_info;

void		ps_insn_exec(t_insn insn, t_stack *a, t_stack *b);
const char	*ps_insn_name(t_insn insn);
t_insn		ps_insn_from_name(const char *name);

void		ps_insn_pa(t_stack *a, t_stack *b);
void		ps_insn_pb(t_stack *a, t_stack *b);
void		ps_insn_sa(t_stack *a, t_stack *b);
void		ps_insn_sb(t_stack *a, t_stack *b);
void		ps_insn_ss(t_stack *a, t_stack *b);
void		ps_insn_ra(t_stack *a, t_stack *b);
void		ps_insn_rb(t_stack *a, t_stack *b);
void		ps_insn_rr(t_stack *a, t_stack *b);
void		ps_insn_rra(t_stack *a, t_stack *b);
void		ps_insn_rrb(t_stack *a, t_stack *b);
void		ps_insn_rrr(t_stack *a, t_stack *b);

#endif
