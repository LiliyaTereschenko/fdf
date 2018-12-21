/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:42:20 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:19:56 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	ft_key(int key, t_mlx *fdf)
{
	if (key == 124)
	{
		fdf->ang_X += 0.005;
		ft_rotation_x(&(fdf->map), fdf);
	}
	if (key == 126)
	{
		fdf->ang_Y += 0.005;
		ft_rotation_y(&(fdf->map), fdf);
	}
	if (key == 125)
	{
		fdf->ang_Z += 0.005;
		ft_rotation_z(&(fdf->map), fdf);
	}
	if (key == 69)
	{
		fdf->zoom += 1;
		ft_zoom(&(fdf->map), fdf);
	}
	
}

int ft_press_key(int key, t_mlx *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit (0);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_key(key, fdf);
	ft_draw_figure(fdf->map, fdf);
	return (0);
}

int		main(int argc, char **argv)
{
	t_point	**map;
	t_mlx	*fdf;
	
	map = NULL;
	if (argc == 2)
	{
		if ((ft_read_map(argv[1], &map)))
		{	
			fdf = (t_mlx *)malloc(sizeof(t_mlx));
			fdf->ang_X = 0;
			fdf->ang_Y = 0;
			fdf->ang_Z = 0;
			fdf->zoom = 2;
			fdf->win_size_x = (map[0][0].x * 50) < 1500 ? map[0][0].x * 50 : 1500;
			fdf->win_size_y = (map[0][0].y * 50) < 1200 ? map[0][0].y * 50 : 1200;
			fdf->mlx = mlx_init();
			fdf->win = mlx_new_window(fdf->mlx, fdf->win_size_x, fdf->win_size_y, "fdf");
			fdf->map = map;
			ft_move_to_center(fdf, &map);
			mlx_key_hook(fdf->win, ft_press_key, fdf);
			ft_draw_figure(map, fdf);
			//ft_print_map(map);
			mlx_loop(fdf->mlx);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fdf file_name\n");
	return (0);
}
