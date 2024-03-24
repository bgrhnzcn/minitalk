/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:52:39 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/03/24 10:16:39 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received = 0;

static void	sig_handler(int sig)
{
	(void)sig;
	g_received++;
}

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
				pause();
			}
			else
			{
				kill(pid, SIGUSR2);
				pause();
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
	struct sigaction	sa;

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
	sa.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &sa, 0);
	send = send_signal(ft_atoi(argv[1]), argv[2]);
	ft_printf("Send: %u\nReceived: %u\n", send, g_received);
	return (0);
}
