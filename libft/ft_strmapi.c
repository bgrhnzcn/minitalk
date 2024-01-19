/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:41 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/21 18:21:30 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			lenght;
	char			*res;

	lenght = ft_strlen(s);
	res = malloc(lenght + 1);
	if (res == NULL)
		return (NULL);
	index = 0;
	while (index < lenght)
	{
		res[index] = f(index, s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
