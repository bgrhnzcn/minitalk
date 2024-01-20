/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:51:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/20 21:00:52 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig)
{
	static char	c;
	static int	i = 7;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		ft_putchar(c);
		c = 0;
		i = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		usleep(1);
	return (0);
}
