/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:51:37 by buozcan           #+#    #+#             */
/*   Updated: 2023/11/22 14:52:28 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	int		len;
	int		check;
	va_list	arg;
}	t_printf;

int		ft_printf(const char *str, ...);
int		ft_print_format(va_list arg, char c);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(long nb);
int		ft_putunbr(unsigned long nb);
int		ft_puthex(unsigned char c, char is_lower);
int		ft_putnbr_hex(unsigned int nb, char is_lower);
int		ft_putnbr_lhex(unsigned long nb, char is_lower);
int		ft_putnbr_pointer(void *p);
size_t	ft_strlen(const char *str);
#endif
