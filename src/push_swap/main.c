/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:44:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/18 04:49:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps/stack.h>

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)argc;
	(void)argv;
	stack_a = ps_stack_init(10);
	stack_b = ps_stack_init(10);
	ps_stack_print(stack_a);
	ps_stack_print(stack_b);
	ps_stack_r_push(stack_a, 1);
	ps_stack_r_push(stack_a, 2);
	ps_stack_r_push(stack_a, 3);
	ps_stack_r_push(stack_b, 3);
	ps_stack_r_push(stack_b, 4);
	ps_stack_r_push(stack_b, 5);
	ps_stack_print(stack_a);
	ps_stack_print(stack_b);
	ps_stack_rotate(stack_a);
	ps_stack_print(stack_a);
	ps_stack_free(&stack_a);
	ps_stack_free(&stack_b);
	return (0);
}
