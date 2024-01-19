/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:22:36 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/18 18:27:18 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	ft_vec3_set(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3	ft_vec3_add(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

t_vec3	ft_vec3_sub(t_vec3	vec1, t_vec3 vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return (vec1);
}

t_vec3	ft_vec3_mul(t_vec3 vec, double mul)
{
	vec.x *= mul;
	vec.y *= mul;
	vec.z *= mul;
	return (vec);
}

t_vec3	ft_vec3_div(t_vec3 vec, double div)
{
	vec.x /= div;
	vec.y /= div;
	vec.z /= div;
	return (vec);
}
