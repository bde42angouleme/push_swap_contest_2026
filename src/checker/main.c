/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:08:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 03:01:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/data/list.h>
#include <ft/io.h>
#include <ft/print.h>
#include <ps/insn.h>
#include <ps/parser.h>
#include <stdlib.h>

static int	ps_execute(t_stack *a, t_stack *b, t_list *list)
{
	t_list	*curr;

	curr = list;
	while (curr)
	{
		ps_insn_exec(ps_insn_from_name(curr->content), a, b);
		curr = curr->next;
	}
	if (ps_stack_is_sorted(a) && ps_stack_is_empty(b))
		ft_putendl_fd(1, "OK");
	else
		ft_putendl_fd(1, "KO");
	return (0);
}

static int	ps_parse_input(char *input, t_list **list)
{
	t_insn	insn;

	input[ft_strlen(input) - 1] = '\0';
	insn = ps_insn_from_name(input);
	if (insn == NONE)
		return (-1);
	ft_lstadd_back(list, ft_lstnew(ft_strdup(input)));
	return (0);
}

static int	ps_checker_loop(t_stack *a, t_stack *b)
{
	char	*input;
	int		ret;
	t_list	*list;

	list = NULL;
	ret = 0;
	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (ps_parse_input(input, &list) == -1)
		{
			free(input);
			ret = -1;
			break ;
		}
		free(input);
	}
	if (ret != -1)
		ret = ps_execute(a, b, list);
	ft_lstclear(&list, free);
	return (ret);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		ret;

	ret = 0;
	b = NULL;
	if (argc > 1)
	{
		a = ps_parse_stack(argc, argv);
		if (!a)
			ret = -1;
		else
		{
			b = ps_stack_init(a->capacity);
			if (!b)
				ret = -1;
		}
		if (ret != -1)
			ret = ps_checker_loop(a, b);
		ps_stack_free(&a);
		ps_stack_free(&b);
	}
	if (ret == -1)
		ft_putendl_fd(2, "Error");
	return (ret);
}
