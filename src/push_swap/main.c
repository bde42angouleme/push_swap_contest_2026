/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:44:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/02 22:05:13 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>
#include <ft/print.h>
#include <ps/error.h>
#include <ps/insn.h>
#include <ps/parser.h>
#include <ps/sort.h>
#include <ps/stack.h>
#include <stdlib.h>

void	ps_debug_print(t_stack *a, t_stack *b)
{
	size_t	max;

	ft_printf("Stack A\tStack B\n");
	ft_printf("-------\t-------\n");
	max = ft_max(a->size, b->size);
	while (max--)
	{
		if (a->size > max)
			ft_printf("%7d", a->values[max]);
		else
			ft_printf("%7c", ' ');
		if (b->size > max)
			ft_printf("\t%d", b->values[max]);
		ft_printf("\n");
	}
	ft_printf("-------\t-------\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (-1);
	stack_a = ps_parse_stack(argc, argv);
	if (!stack_a)
		ps_error();
	stack_b = ps_stack_init(stack_a->size);
	if (!stack_b)
	{
		ps_stack_free(&stack_a);
		ps_error();
	}
	if (!ps_stack_is_sorted(stack_a))
	{
		ps_insn_set_should_print(true);
		ps_sort(stack_a, stack_b);
	}
	ps_stack_free(&stack_a);
	ps_stack_free(&stack_b);
	return (0);
}
