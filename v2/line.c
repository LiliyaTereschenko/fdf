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

static void draw_line_X(int x0, int y0, int x1, int y1, t_mlx *param)
{
	int err;
	int dx;
	int dy;
	int sgn_y;

	dx = ((x1 - x0) > 0) ? (x1 - x0) : (x0 - x1);
	dy = ((y1 - y0) > 0) ? (y1 - y0) : (y0 - y1);
	sgn_y = ((y1 - y0) > 0) ? 1 : -1;
    err = dx / 2;
	while (x0 <= x1)
	{
		mlx_pixel_put(param->mlx, param->win, x0, y0, 0xFFAAFF);
		err -= dy;
		if (err < 0)
		{
			err += dx;
			y0 += sgn_y;
		}
		x0++;
	}
}

static void draw_line_Y(int x0, int y0, int x1, int y1, t_mlx *param)
{
	int err;
	int dx;
	int dy;
	//int sgn_y;
	int sgn_x;

	dx = ((x1 - x0) > 0) ? (x1 - x0) : (x0 - x1);
	dy = ((y1 - y0) > 0) ? (y1 - y0) : (y0 - y1);
	sgn_x = ((x1 - x0) > 0) ? 1 : -1;
	err = dy / 2;
		while (y0 <= y1)
		{
			mlx_pixel_put(param->mlx, param->win, x0, y0, 0xBBFFFF);
			err -= dx;
			if (err < 0)
			{
				err += dy;
				x0 += sgn_x;
			}
			y0++;
		}
}

void	line(int x0, int y0, int x1, int y1, t_mlx *param)
{
	int dx;
	int dy;
	
	dx = ((x1 - x0) > 0) ? (x1 - x0) : (x0 - x1);
	dy = ((y1 - y0) > 0) ? (y1 - y0) : (y0 - y1);
	if (dx > dy)
	{
		if (x0 > x1)
			draw_line_X(x1, y1, x0, y0, param);
		else
			draw_line_X(x0, y0, x1, y1, param);
	}
	else
	{
		if (y0 > y1)
			draw_line_Y(x1, y1, x0, y0, param);
		else
			draw_line_Y(x0, y0, x1, y1, param);
	}
}

/*
void sun(int x0, int y0, t_mlx *param)
{
	float r = 200;
    int dx;
    int dy;
    for(int i = 0; i < 360; i+=5)
    {
        dx = r * cos(3.1415 * i/ 180.0);
        dy = r * sin(3.1415 * i/ 180.0);
        line(x0, y0, x0 + dx, y0 + dy, param);
    }
}
*/