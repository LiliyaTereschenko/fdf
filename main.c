/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:42:20 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/25 11:58:57 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(t_mlx *fdf)
{
	int	i;

	i = 0;
	while (i < 2560)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, i, 50, 0xFFAAFF);
		i++;
	}
	mlx_string_put(fdf->mlx, fdf->win, 30, 15, 0xFFAAFF, "KEY PRESS:");
	mlx_string_put(fdf->mlx, fdf->win, 140, 15, 0xFFAAFF, "rotation:");
	mlx_string_put(fdf->mlx, fdf->win, 240, 15, 0xBBFFFF, "Ox - 1 2, Oy - 4 5, \
		Oz - 7 8");
	mlx_string_put(fdf->mlx, fdf->win, 550, 15, 0xFFAAFF, "zoom:");
	mlx_string_put(fdf->mlx, fdf->win, 600, 15, 0xBBFFFF, " + - ");
}

int			ft_make_copy(t_mlx *fdf)
{
	int i;
	int j;

	i = 0;
	(fdf->map_tmp) = (t_point **)malloc(sizeof(t_point *) * (fdf->max_Y));
	if (!(fdf->map_tmp))
		return (0);
	while (i < fdf->max_Y)
	{
		j = 0;
		(fdf->map_tmp)[i] = (t_point *)malloc(sizeof(t_point) * (fdf->max_X));
		if (!(fdf->map_tmp)[i])
			return (0);
		while (j < fdf->max_X)
		{
			(fdf->map_tmp)[i][j].x = (fdf->map)[i][j].x;
			(fdf->map_tmp)[i][j].y = (fdf->map)[i][j].y;
			(fdf->map_tmp)[i][j].z = (fdf->map)[i][j].z;
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_init_structure(t_mlx *fdf)
{
	fdf->ang_X = 0;
	fdf->ang_Y = 0;
	fdf->ang_Z = 0;
	fdf->win_size_x = (fdf->max_X * 70) < 2000 ? fdf->max_X * 70 : 2000;
	fdf->win_size_y = (fdf->max_Y * 70) < 1200 ? fdf->max_Y * 70 : 1200;
	fdf->zoom = (fdf->max_Y * 70) < 1200 ? fdf->max_Y : 2;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_size_x, fdf->win_size_y,\
		"fdf");
	fdf->start_X = fdf->win_size_x / 2;
	fdf->start_Y = fdf->win_size_y / 2;
}

int			main(int argc, char **argv)
{
	t_point	**map;
	t_mlx	*fdf;

	fdf = (t_mlx *)malloc(sizeof(t_mlx));
	map = NULL;
	if (argc == 2)
	{
		if ((ft_read_map(argv[1], &map, fdf)))
		{
			ft_init_structure(fdf);
			fdf->map = map;
			print_menu(fdf);
			ft_make_copy(fdf);
			ft_change_matrix(fdf);
			mlx_key_hook(fdf->win, ft_press_key, fdf);
			ft_draw_figure(fdf->map_tmp, fdf);
			mlx_loop(fdf->mlx);
		}
		else
			ft_putendl_fd("error", 2);
	}
	else
		ft_putstr("usage: ./fdf file_name\n");
	return (0);
}
