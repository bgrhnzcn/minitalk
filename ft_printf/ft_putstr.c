/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:25:03 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/17 20:37:17 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(1, str, ft_strlen(str)) == -1)
		return (-1);
	return (ft_strlen(str));
}
