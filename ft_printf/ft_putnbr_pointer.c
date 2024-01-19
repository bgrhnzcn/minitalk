/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:04:58 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/17 22:50:14 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lhex(unsigned long nb, char is_lower)
{
	static int	digit;
	int			check;

	digit = 0;
	if (nb > 15)
	{
		if (ft_putnbr_lhex(nb / 16, is_lower) == -1)
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

int	ft_putnbr_pointer(void *p)
{
	long	adress;
	int		digit;
	int		check;

	digit = 2;
	adress = (long)p;
	if (ft_putstr("0x") == -1)
		return (-1);
	check = ft_putnbr_lhex(adress, 1);
	if (check == -1)
		return (-1);
	digit += check;
	return (digit);
}
