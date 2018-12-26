/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:17:16 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/19 11:17:22 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_x(t_line *l, t_mlx *fdf)
{
	int err;
	int dx;
	int dy;
	int sgn_y;

	dx = ((l->x1 - l->x0) > 0) ? (l->x1 - l->x0) : (l->x0 - l->x1);
	dy = ((l->y1 - l->y0) > 0) ? (l->y1 - l->y0) : (l->y0 - l->y1);
	sgn_y = ((l->y1 - l->y0) > 0) ? 1 : -1;
	err = dx / 2;
	while (l->x0 <= l->x1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, l->x0, l->y0, 0xFFAAFF);
		err -= dy;
		if (err < 0)
		{
			err += dx;
			l->y0 += sgn_y;
		}
		l->x0++;
	}
}

static void	draw_line_y(t_line *l, t_mlx *fdf)
{
	int err;
	int dx;
	int dy;
	int sgn_x;

	dx = ((l->x1 - l->x0) > 0) ? (l->x1 - l->x0) : (l->x0 - l->x1);
	dy = ((l->y1 - l->y0) > 0) ? (l->y1 - l->y0) : (l->y0 - l->y1);
	sgn_x = ((l->x1 - l->x0) > 0) ? 1 : -1;
	err = dy / 2;
	while (l->y0 <= l->y1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, l->x0, l->y0, 0xBBFFFF);
		err -= dx;
		if (err < 0)
		{
			err += dy;
			l->x0 += sgn_x;
		}
		l->y0++;
	}
}

static void	ft_swap(int a, int b)
{
	int c;

	c = a;
	a = b;
	b = c;
}

void		line(t_line *l, t_mlx *fdf)
{
	int dx;
	int dy;

	dx = ((l->x1 - l->x0) > 0) ? (l->x1 - l->x0) : (l->x0 - l->x1);
	dy = ((l->y1 - l->y0) > 0) ? (l->y1 - l->y0) : (l->y0 - l->y1);
	if (dx > dy)
	{
		if (l->x0 > l->x1)
			ft_swap(l->x0, l->x1);
		draw_line_x(l, fdf);
	}
	else
	{
		if (l->y0 > l->y1)
			ft_swap(l->y0, l->y1);
		draw_line_y(l, fdf);
	}
}
