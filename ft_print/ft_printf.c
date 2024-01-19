/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:36:05 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/22 14:44:05 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list arg, char c)
{
	int	check;

	check = 0;
	if (c == 'c')
		check += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		check += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		check += ft_putnbr_pointer(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		check += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		check += ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		check += ft_putnbr_hex(va_arg(arg, int), 1);
	else if (c == 'X')
		check += ft_putnbr_hex(va_arg(arg, int), 0);
	else if (c == '%')
		check += ft_putchar('%');
	return (check);
}

void	ft_init(t_printf *ft)
{
	ft->len = 0;
	ft->check = 0;
}

int	ft_printf(const char *str, ...)
{
	t_printf	ft;

	ft_init(&ft);
	va_start(ft.arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft.check = ft_print_format(ft.arg, *(str + 1));
			if (ft.check == -1)
				return (-1);
			ft.len += ft.check;
			str += 1;
		}
		else
		{
			ft.check = ft_putchar(*str);
			if (ft.check == -1)
				return (-1);
			ft.len += ft.check;
		}
		str++;
	}
	va_end(ft.arg);
	return (ft.len);
}
