/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:11:17 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*point;

	point = (img->data) + ((img->bits_per_pixel / 8) * x)
		+ (img->size_line * y);
	*(unsigned int *)point = color.value;
}

void	ft_draw_tri(t_data *data, t_tri *tris, int j, t_color color)
{
	ft_draw_line(data, tris[j].pts[0],
		tris[j].pts[1], color);
	ft_draw_line(data, tris[j].pts[1],
		tris[j].pts[2], color);
	ft_draw_line(data, tris[j].pts[2],
		tris[j].pts[0], color);
}

void	ft_fill_img(t_data *data, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->win.width)
	{
		j = 0;
		while (j < data->win.height)
		{
			ft_put_pixel(&(data->img), i, j, color);
			j++;
		}
		i++;
	}
}
