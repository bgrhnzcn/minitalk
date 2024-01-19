/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_vec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:17:40 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/18 18:35:17 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	ft_vec3_inv(t_vec3 vec)
{
	t_vec3	vec3_res;

	vec3_res.x = -vec.x;
	vec3_res.y = -vec.y;
	vec3_res.z = -vec.z;
	return (vec3_res);
}

t_vec3	ft_vec3_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec_res;

	vec_res.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	vec_res.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	vec_res.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (vec_res);
}

t_vec3	ft_vec3_norm(t_vec3 vec)
{
	return (ft_vec3_div(vec, ft_vec3_mag(vec)));
}
