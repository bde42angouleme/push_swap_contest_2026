/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:13:26 by nredouan          #+#    #+#             */
/*   Updated: 2025/10/22 19:03:36 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	int		i;

	i = 0;
	if (size != 0 && nmemb != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	array = malloc((nmemb * size));
	if (!array)
		return (NULL);
	while (array[i])
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}
