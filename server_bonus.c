/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:51:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/20 20:45:42 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i = 7;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		ft_putchar(c);
		c = 0;
		i = 7;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		usleep(1);
	return (0);
}
