/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:49:01 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/25 12:49:10 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key(int key, t_mlx *fdf)
{
	if (key == 83)
		fdf->ang_x += 0.05;
	if (key == 84)
		fdf->ang_x -= 0.05;
	if (key == 86)
		fdf->ang_y += 0.05;
	if (key == 87)
		fdf->ang_y -= 0.05;
	if (key == 89)
		fdf->ang_z += 0.05;
	if (key == 91)
		fdf->ang_z -= 0.05;
	if (key == 69)
		fdf->zoom += 1;
	if (key == 78 && fdf->zoom > 1)
		fdf->zoom -= 1;
}

int		ft_press_key(int key, t_mlx *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_key(key, fdf);
	ft_change_matrix(fdf);
	print_menu(fdf);
	ft_draw_figure(fdf->map_tmp, fdf);
	return (0);
}
