/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:28:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/10/21 21:18:04 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nsize;

	nsize = ft_strlen(needle);
	if (nsize == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, nsize) == 0 && i + nsize <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
