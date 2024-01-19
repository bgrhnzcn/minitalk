/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:24:47 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:34:08 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_vec2_dot(t_vec2 vec1, t_vec2 vec2)
{
	double	res;

	res = 0;
	res += vec1.x * vec2.x;
	res += vec1.y * vec2.y;
	return (res);
}

double	ft_get_dist2(t_vec2 point1, t_vec2 point2)
{
	double	dist_x;
	double	dist_y;

	dist_x = fabs(point1.x - point2.x);
	dist_y = fabs(point1.y - point2.y);
	return (sqrt(pow(dist_x, 2) * pow(dist_y, 2)));
}

double	ft_vec2_mag(t_vec2 vec)
{
	t_vec2	vec_null;

	vec_null.x = 0;
	vec_null.y = 0;
	return (ft_get_dist2(vec_null, vec));
}
