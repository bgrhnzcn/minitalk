/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:52:39 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/20 17:19:40 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 700
#define WAIT_TIME 100
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>

void	send_signal(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = (sizeof(char) * 8) - 1;
		while (i >= 0)
		{
			if (*str & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			//ft_printf("worked");
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;

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
	pid = ft_atoi(argv[1]);
	ft_printf("%s, %d\n", argv[2], getpid());
	send_signal(pid, argv[2]);
	return (0);
}
