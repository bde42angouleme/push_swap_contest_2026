/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:54:25 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 02:56:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string.h>
#include <ps/parser.h>
#include <ps/stack.h>
#include <stdlib.h>

static size_t	ps_argsize(char *str)
{
	size_t	size;
	char	**arr;

	size = 0;
	arr = ft_splits(str, " \n");
	if (!arr)
		return (0);
	while (arr[size])
	{
		free(arr[size]);
		size++;
	}
	free(arr);
	return (size);
}

static size_t	ps_stacksize(int argc, char **argv)
{
	size_t	size;

	size = 0;
	while (--argc > 0)
		size += ps_argsize(argv[argc]);
	return (size);
}

t_stack	*ps_parse_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**arr;
	int		i;

	stack = ps_stack_init(ps_stacksize(argc, argv));
	if (!stack)
		return (NULL);
	while (--argc > 0)
	{
		arr = ft_splits(argv[argc], " \n");
		if (!arr)
			ps_stack_free(&stack);
		while (arr && *arr)
		{
			if (stack && (ft_strtoi(*arr, &i) || ps_stack_contains(stack, i)))
				ps_stack_free(&stack);
			if (stack)
				ps_stack_r_push(stack, i);
			free(*arr);
			arr++;
		}
		free(arr - ps_argsize(argv[argc]));
	}
	return (stack);
}
