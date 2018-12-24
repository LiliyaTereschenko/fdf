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
	if (key == 83)
		fdf->ang_X += 0.05;
	if (key == 84)
		fdf->ang_X -= 0.05;
	if (key == 86)
		fdf->ang_Y += 0.05;
	if (key == 87)
		fdf->ang_Y -= 0.05;
	if (key == 89)
		fdf->ang_Z += 0.05;
	if (key == 91)
		fdf->ang_Z -= 0.05;
	if (key == 69)
		fdf->zoom += 1;
	if (key == 78 && fdf->zoom > 1)
		fdf->zoom -= 1;
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
	ft_change_matrix(fdf);
	ft_draw_figure(fdf->map_tmp, fdf);
	return (0);
}

void	ft_make_copy(t_mlx *fdf)
{
    int i;
    int j;
   
	i = 0;
    while (i < fdf->max_Y)
    {
        j = 0;
        while (j < fdf->max_X)
        {
            (fdf->map_tmp)[i][j].x = (fdf->map)[i][j].x;
            (fdf->map_tmp)[i][j].y = (fdf->map)[i][j].y;
			(fdf->map_tmp)[i][j].z = (fdf->map)[i][j].z;
			j++;        
        }
		i++;
    }
}

int		main(int argc, char **argv)
{
	t_point	**map;
	t_mlx	*fdf;
	
	fdf = (t_mlx *)malloc(sizeof(t_mlx));
	map = NULL;
	if (argc == 2)
	{
		if ((ft_read_map(argv[1], &map, fdf)))
		{	
			
			fdf->ang_X = 0;
			fdf->ang_Y = 0;
			fdf->ang_Z = 0;
			fdf->win_size_x = (fdf->max_X * 70) < 2000 ? fdf->max_X * 70 : 2000;
			fdf->win_size_y = (fdf->max_Y * 70) < 1200 ? fdf->max_Y * 70 : 1200;
			fdf->zoom = (fdf->max_Y * 70) < 1200 ? fdf->max_Y : 1;
			fdf->mlx = mlx_init();
			fdf->win = mlx_new_window(fdf->mlx, fdf->win_size_x, fdf->win_size_y, "fdf");
			fdf->map = map;
			fdf->start_X = fdf->win_size_x / 2;
			fdf->start_Y = fdf->win_size_y / 2;
			ft_make_copy(fdf);
			ft_change_matrix(fdf);
			mlx_key_hook(fdf->win, ft_press_key, fdf);
			printf("map\n");
			ft_print_map(fdf->map, fdf);
			printf("tmp_map\n");
			ft_print_map(fdf->map_tmp, fdf);
			ft_draw_figure(fdf->map_tmp, fdf);
			mlx_loop(fdf->mlx);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fdf file_name\n");
	return (0);
}
