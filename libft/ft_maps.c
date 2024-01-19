/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:42:29 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_normalize(double val, double min, double max)
{
	if (max == min)
		return (1);
	return ((val - min) / (max - min));
}

double	ft_lerp(double val, double min, double max)
{
	return ((val * (max - min)) + min);
}

double	ft_map(double val, t_map map)
{
	return (ft_lerp(ft_normalize(val, map.min_i, map.min_o),
			map.min_o, map.max_o));
}

t_map	ft_map_init(double min_i, double max_i, double min_o, double max_o)
{
	t_map	map;

	map.max_i = max_i;
	map.max_o = max_o;
	map.min_i = min_i;
	map.min_o = min_o;
	return (map);
}
