/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:07:43 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/19 00:27:24 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned char c, char is_lower)
{
	if (c < 10)
		c += 48;
	else if (c < 16 && is_lower)
		c += 87;
	else
		c += 55;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_hex(unsigned int nb, char is_lower)
{
	static int	digit;
	int			check;

	digit = 0;
	if (nb > 15)
	{
		if (ft_putnbr_hex(nb / 16, is_lower) == -1)
			return (-1);
		nb = nb % 16;
		check = ft_puthex(nb, is_lower);
		if (check == -1)
			return (-1);
		digit += check;
	}
	else
	{
		check = ft_puthex(nb, is_lower);
		if (check == -1)
			return (-1);
		digit += check;
	}
	return (digit);
}
