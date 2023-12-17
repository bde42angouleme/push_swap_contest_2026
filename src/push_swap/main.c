/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:44:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/17 10:15:36 by kiroussa         ###   ########.fr       */
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

static void	ps_iterate(void *data)
{
	ft_putendl((char *) data);
}

static void	ps_handle_sort(t_stack *a, t_stack *b)
{
	t_list	*list;

	if (ps_stack_is_sorted(a))
		return ;
	list = ps_sort(a, b);
	if (!list)
		ps_error();
	ft_lst_foreach(list, ps_iterate);
	ft_lst_free(&list, NULL);
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
	ps_handle_sort(stack_a, stack_b);
	ps_stack_free(&stack_b);
	return (0);
}
