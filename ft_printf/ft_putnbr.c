/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:36:22 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/22 15:06:36 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}

static void	*ft_calloc(size_t nmemb, size_t size)
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

int	ft_count_digit(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_putnbr(long nb)
{
	char	*str;
	int		i;
	int		res;

	i = ft_count_digit(nb);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (-1);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[i] = 0;
	while (i > 0)
	{
		if (str[i - 1] == '-')
			break ;
		str[i - 1] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	res = ft_putstr(str);
	free(str);
	return (res);
}
