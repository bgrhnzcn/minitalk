/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:34:23 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/19 00:00:51 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned long nb)
{
	int	digit;
	int	check;

	digit = 0;
	if (nb > 9)
	{
		check = ft_putnbr(nb / 10);
		if (check == -1)
			return (-1);
		digit += check;
		nb = nb % 10;
		check = ft_putchar(48 + nb);
		if (check == -1)
			return (-1);
		digit += check;
	}
	else
	{
		check = ft_putchar(48 + nb);
		if (check == -1)
			return (-1);
		digit += check;
	}
	return (digit);
}
