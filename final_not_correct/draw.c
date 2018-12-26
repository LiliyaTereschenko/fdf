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
	(fdf->map_tmp)[i][j].z = ((fdf->map)[i][j].x * (sin(fdf->ang_x) *\
				sin(fdf->ang_z) - cos(fdf->ang_x) * sin(fdf->ang_y) *\
				cos(fdf->ang_z)) + (fdf->map)[i][j].y * (cos(fdf->ang_x) *\
				sin(fdf->ang_y) * sin(fdf->ang_z) + sin(fdf->ang_x) *\
				cos(fdf->ang_z)) + (fdf->map)[i][j].z * cos(fdf->ang_x) *\
				cos(fdf->ang_y)) * (fdf->zoom);
}

void		ft_change_matrix(t_mlx *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->max_y)
	{
		j = 0;
		while (j < fdf->max_x)
		{
			(fdf->map_tmp)[i][j].x = ((fdf->map)[i][j].x * cos(fdf->ang_y) *\
					cos(fdf->ang_z) - (fdf->map)[i][j].y * cos(fdf->ang_y) *\
					sin(fdf->ang_z) + (fdf->map)[i][j].z * sin(fdf->ang_y)) *\
					(fdf->zoom) + fdf->start_x;
			(fdf->map_tmp)[i][j].y = ((fdf->map)[i][j].x * (sin(fdf->ang_x) *\
						sin(fdf->ang_y) * cos(fdf->ang_z) + cos(fdf->ang_x) *\
						sin(fdf->ang_z)) + (fdf->map)[i][j].y *\
						(cos(fdf->ang_x) * cos(fdf->ang_z) - sin(fdf->ang_x) *\
						sin(fdf->ang_y) * sin(fdf->ang_z)) -\
						(fdf->map)[i][j].z * cos(fdf->ang_y) * sin(fdf->ang_x))\
						* (fdf->zoom) + fdf->start_y;
			ft_change_z(fdf, i, j);
			j++;
		}
		i++;
	}
}

static void	ft_draw_first(t_point **m, t_line *l, t_mlx *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->max_y)
	{
		j = 0;
		while (j < fdf->max_x - 1)
		{
			l->x0 = m[i][j].x;
			l->y0 = m[i][j].y;
			l->x1 = m[i][j + 1].x;
			l->y1 = m[i][j + 1].y;
			line(l, fdf);
			j++;
		}
		i++;
	}
}

static void	ft_draw_second(t_point **m, t_line *l, t_mlx *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (j < fdf->max_x)
	{
		i = 0;
		while (i < fdf->max_y - 1)
		{
			l->x0 = m[i][j].x;
			l->y0 = m[i][j].y;
			l->x1 = m[i + 1][j].x;
			l->y1 = m[i + 1][j].y;
			line(l, fdf);
			i++;
		}
		j++;
	}
}

void		ft_draw_figure(t_point **m, t_mlx *fdf)
{
	t_line	*l;

	l = (t_line *)malloc(sizeof(t_line));
	ft_draw_first(m, l, fdf);
	ft_draw_second(m, l, fdf);
}
