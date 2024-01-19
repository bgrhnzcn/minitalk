/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:44:26 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:33:00 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	ft_vec3_to_vec2(t_vec3 vec3)
{
	return (ft_vec2_set(vec3.x, vec3.y));
}

t_vec3	ft_vec2_to_vec3(t_vec2 vec2, double z)
{
	return (ft_vec3_set(vec2.x, vec2.y, z));
}

t_vec4	ft_vec3_to_vec4(t_vec3 vec3, double w)
{
	return (ft_vec4_set(vec3.x, vec3.y, vec3.z, w));
}

t_vec3	ft_vec4_to_vec3(t_vec4 vec4)
{
	return (ft_vec3_set(vec4.x, vec4.y, vec4.z));
}
