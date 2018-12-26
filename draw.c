/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 11:58:22 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/25 14:02:04 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_change_z(t_mlx *fdf, int i, int j)
{
	(fdf->map_tmp)[i][j].z = ((fdf->map)[i][j].x * (sin(fdf->ang_X) *\
				sin(fdf->ang_Z) - cos(fdf->ang_X) * sin(fdf->ang_Y) *\
				cos(fdf->ang_Z)) + (fdf->map)[i][j].y * (cos(fdf->ang_X) *\
				sin(fdf->ang_Y) * sin(fdf->ang_Z) + sin(fdf->ang_X) *\
				cos(fdf->ang_Z)) + (fdf->map)[i][j].z * cos(fdf->ang_X) *\
				cos(fdf->ang_Y)) * (fdf->zoom);
}

void		ft_change_matrix(t_mlx *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->max_Y)
	{
		j = 0;
		while (j < fdf->max_X)
		{
			(fdf->map_tmp)[i][j].x = ((fdf->map)[i][j].x * cos(fdf->ang_Y) *\
					cos(fdf->ang_Z) - (fdf->map)[i][j].y * cos(fdf->ang_Y) *\
					sin(fdf->ang_Z) + (fdf->map)[i][j].z * sin(fdf->ang_Y)) *\
					(fdf->zoom) + fdf->start_X;
			(fdf->map_tmp)[i][j].y = ((fdf->map)[i][j].x * (sin(fdf->ang_X) *\
						sin(fdf->ang_Y) * cos(fdf->ang_Z) + cos(fdf->ang_X) *\
						sin(fdf->ang_Z)) + (fdf->map)[i][j].y *\
						(cos(fdf->ang_X) * cos(fdf->ang_Z) - sin(fdf->ang_X) *\
						sin(fdf->ang_Y) * sin(fdf->ang_Z)) -\
						(fdf->map)[i][j].z * cos(fdf->ang_Y) * sin(fdf->ang_X))\
						* (fdf->zoom) + fdf->start_Y;
			ft_change_z(fdf, i, j);
			j++;
		}
		i++;
	}
}

void		ft_draw_figure(t_point **m, t_mlx *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->max_Y)
	{
		j = 0;
		while (j < fdf->max_X - 1)
		{
			line(m[i][j].x, m[i][j].y, m[i][j + 1].x, m[i][j + 1].y, fdf);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->max_X)
	{
		i = 0;
		while (i < fdf->max_Y - 1)
		{
			line(m[i][j].x, m[i][j].y, m[i + 1][j].x, m[i + 1][j].y, fdf);
			i++;
		}
		j++;
	}
}
