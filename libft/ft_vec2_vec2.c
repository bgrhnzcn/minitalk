/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_vec2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:32:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:34:27 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	ft_vec2_inv(t_vec2 vec)
{
	t_vec2	vec2_res;

	vec2_res.x = -vec.x;
	vec2_res.y = -vec.y;
	return (vec2_res);
}

t_vec2	ft_vec2_norm(t_vec2 vec)
{
	return (ft_vec2_div(vec, ft_vec2_mag(vec)));
}
