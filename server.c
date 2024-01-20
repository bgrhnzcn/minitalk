/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:51:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/20 16:58:32 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 700
#define WAIT_TIME 1
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>

int	pid;

void	handle_sigusr(int sig, siginfo_t *info, void * context)
{
	static char	c;
	static int	i = (sizeof(char) * 8) - 1;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		ft_putchar(c);
		c = 0;
		i = (sizeof(char) * 8) - 1;
	}
	ft_printf("%d", info->si_pid);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
