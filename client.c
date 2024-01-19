/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:52:39 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/19 03:36:27 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*message;

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
	message = argv[2];
	ft_printf("%s, %d\n", message, pid);
	return (0);
}
