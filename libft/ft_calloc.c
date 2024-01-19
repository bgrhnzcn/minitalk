/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:33 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/11 15:10:33 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	buffsize;

	buffsize = nmemb * size;
	res = malloc(buffsize);
	if (res == NULL)
		return (res);
	ft_bzero(res, buffsize);
	return (res);
}
