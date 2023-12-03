/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:54:25 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/02 22:51:15 by kiroussa         ###   ########.fr       */
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
	t_stack	*s;
	char	**arr;
	int		i;
	int		j;

	s = ps_stack_init(ps_stacksize(argc, argv));
	if (!s)
		return (NULL);
	j = 0;
	while (++j < argc)
	{
		arr = ft_splits(argv[j], " \n");
		if (!arr || !*arr)
			ps_stack_free(&s);
		while (arr && *arr)
		{
			if (s && (!**arr || ft_strtoi(*arr, &i) || ps_stack_contains(s, i)))
				ps_stack_free(&s);
			if (s)
				ps_stack_r_push(s, i);
			free(*arr++);
		}
		free(arr - ps_argsize(argv[j]));
	}
	return (s);
}
