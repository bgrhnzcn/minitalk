/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx3_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:57:53 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/18 18:30:13 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	ft_get_row3(t_mtx3 mtx, int row_val)
{
	t_vec3	vec_res;

	if (row_val == 1)
		vec_res = ft_vec3_set(mtx.col1.x, mtx.col2.x, mtx.col3.x);
	else if (row_val == 2)
		vec_res = ft_vec3_set(mtx.col1.y, mtx.col2.y, mtx.col3.y);
	else if (row_val == 3)
		vec_res = ft_vec3_set(mtx.col1.z, mtx.col2.z, mtx.col3.z);
	else
		vec_res = ft_vec3_set(0, 0, 0);
	return (vec_res);
}

void	ft_set_row3(t_mtx3 *mtx, int row_val, t_vec3 row)
{
	if (row_val == 1)
	{
		mtx->col1.x = row.x;
		mtx->col2.x = row.y;
		mtx->col3.x = row.z;
	}
	else if (row_val == 2)
	{
		mtx->col1.y = row.x;
		mtx->col2.y = row.y;
		mtx->col3.y = row.z;
	}
	else if (row_val == 3)
	{
		mtx->col1.z = row.x;
		mtx->col2.z = row.y;
		mtx->col3.z = row.z;
	}
}

t_vec3	ft_mtx_vec_mul3(t_mtx3 mtx, t_vec3 vec)
{
	t_vec3	vec_res;
	t_vec3	col1;
	t_vec3	col2;
	t_vec3	col3;

	col1 = mtx.col1;
	col2 = mtx.col2;
	col3 = mtx.col3;
	vec_res.x = ((vec.x * col1.x) + (vec.y * col1.y) + (vec.z * col1.z));
	vec_res.y = ((vec.x * col2.x) + (vec.y * col2.y) + (vec.z * col2.z));
	vec_res.z = ((vec.x * col3.x) + (vec.y * col3.y) + (vec.z * col3.z));
	return (vec_res);
}

t_mtx3	ft_mtx_mtx_mul3(t_mtx3 mtx1, t_mtx3 mtx2)
{
	t_mtx3	mtx_res;

	ft_set_row3(&mtx_res, 1, ft_mtx_vec_mul3(mtx2, ft_get_row3(mtx1, 1)));
	ft_set_row3(&mtx_res, 2, ft_mtx_vec_mul3(mtx2, ft_get_row3(mtx1, 2)));
	ft_set_row3(&mtx_res, 3, ft_mtx_vec_mul3(mtx2, ft_get_row3(mtx1, 3)));
	return (mtx_res);
}
