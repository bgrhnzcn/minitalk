/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:06:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:28:38 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_drw_ln_hlpr_high(t_draw_line *d)
{
	d->x += d->inc;
	d->side_check = d->side_check + (2 * (d->delta.x - d->delta.y));
}

static void	ft_drw_ln_hlpr_low(t_draw_line *d)
{
	d->y += d->inc;
	d->side_check = d->side_check + (2 * (d->delta.y - d->delta.x));
}

static void	ft_draw_line_low(t_data *dt, t_vec3 pt1, t_vec3 pt2, t_color color)
{
	t_draw_line	d;

	d.delta.x = pt2.x - pt1.x;
	d.delta.y = pt2.y - pt1.y;
	d.inc = 1;
	if (d.delta.y < 0)
	{
		d.inc = -1;
		d.delta.y = -d.delta.y;
	}
	d.side_check = (2 * d.delta.y) - d.delta.x;
	d.y = pt1.y;
	d.x = pt1.x;
	while (d.x < pt2.x && d.x < dt->win.height && d.x > 0)
	{
		if (d.y <= dt->win.height && d.y >= 0 && d.x
			<= dt->win.width && d.x >= 0)
			ft_put_pixel(&dt->img, d.x, d.y, color);
		if (d.side_check > 0)
			ft_drw_ln_hlpr_low(&d);
		else
			d.side_check = d.side_check + (2 * d.delta.y);
		d.x++;
	}
}

static void	ft_draw_line_high(t_data *dt, t_vec3 pt1, t_vec3 pt2, t_color color)
{
	t_draw_line	d;

	d.delta.x = pt2.x - pt1.x;
	d.delta.y = pt2.y - pt1.y;
	d.inc = 1;
	if (d.delta.x < 0)
	{
		d.inc = -1;
		d.delta.x = -d.delta.x;
	}
	d.side_check = (2 * d.delta.x) - d.delta.y;
	d.x = pt1.x;
	d.y = pt1.y;
	while (d.y <= pt2.y)
	{
		if (d.y <= dt->win.height && d.y >= 0 && d.x
			<= dt->win.width && d.x >= 0)
			ft_put_pixel(&dt->img, d.x, d.y, color);
		if (d.side_check > 0)
			ft_drw_ln_hlpr_high(&d);
		else
			d.side_check = d.side_check + (2 * d.delta.x);
		d.y++;
	}
}

void	ft_draw_line(t_data *dt, t_vec3 pt1, t_vec3 pt2, t_color color)
{
	if (fabs(pt2.y - pt1.y) < fabs(pt2.x - pt1.x))
	{
		if (pt1.x > pt2.x)
			ft_draw_line_low(dt, pt2, pt1, color);
		else
			ft_draw_line_low(dt, pt1, pt2, color);
	}
	else
	{
		if (pt1.y > pt2.y)
			ft_draw_line_high(dt, pt2, pt1, color);
		else
			ft_draw_line_high(dt, pt1, pt2, color);
	}
}
