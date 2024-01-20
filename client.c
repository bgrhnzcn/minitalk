/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:52:39 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/20 20:44:41 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long	send_signal(int pid, char *str)
{
	int	i;
	int	send;

	send = 0;
	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str & (1 << i))
			{
				kill(pid, SIGUSR1);
				usleep(5000);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(5000);
			}
			send++;
			i--;
		}
		str++;
	}
	return (send);
}

int	main(int argc, char **argv)
{
	unsigned int		i;
	unsigned int		send;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error: Wrong number of arguments.");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("Error: Invalid process ID.");
			exit(EXIT_FAILURE);
		}
	}
	send = send_signal(ft_atoi(argv[1]), argv[2]);
	ft_printf("Send: %u\n", send);
	return (0);
}
