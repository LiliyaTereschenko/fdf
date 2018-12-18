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

/*
#include "fdf.h"



void printFromHead(t_list *list) 
{
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	t_point	**map;
	
	map = NULL;
	if (argc == 2)
	{
		if ((ft_read_map(argv[1], &map)))
		{
			printf(GREEN "success" RESET "\n");
			//ft_print_map(map);
			
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fdf file_name\n");
	return (0);
}*/

// cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#include "mlx.h"
#include <unistd.h>
#include <math.h> 
#include <stdlib.h>
#define ABS(X) ((X >= 0) ? X : (-X))

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
}					t_mlx;

static int sign(int x)
{
	if (x > 0) 
		return (1);
	else if (x == 0)
		return (0);
	else
		return (-1);
}

void	line(int x0, int y0, int x1, int y1, t_mlx *param)
{
	int dx;
	int dy;
	int sgn_x;
	int sgn_y;
	int es;
	int el;
	int err;

	dx = x1 - x0;
	dy = y1 - y0;
	sgn_x = sign(dx);
	sgn_y = sign(dy);
	dx = ABS(dx);
	dy = ABS(dy);
	el = (dx > dy) ? dx : dy;
	es = (dx > dy) ? dy : dx;
	err = el / 2;
	mlx_pixel_put(param->mlx, param->win, x0, y0, 0xFFAAFF);
	for (int t = 0; t < el; t++)
	{
		err -=es;
		if (err < 0)
		{
			err += el;
			x0 += sgn_x;
			y0 += sgn_y;
		}
		else
		{
			x0 += (dx > dy) ? sgn_x : 0;
			y0 += (dx > dy) ? 0 : sgn_y;
		}
		mlx_pixel_put(param->mlx, param->win, x0, y0, 0xFFAAFF);
	}
}

void sun(int x0, int y0, t_mlx *param)
{
	float r = 100;
    //int x0 = 250;
   // int y0 = 250;
    int dx;
    int dy;
    for(int i = 0; i < 360; i++)
    {
        dx = r * cos(3.1415 * i/ 180.0);
        dy = r * sin(3.1415 * i/ 180.0);
        line(x0, y0, x0 + dx, y0 + dy, param);
    }
}

int deal_key(int key, t_mlx *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit (0);
	}
	//write(1, "X", 1);
	return (0);
}

int main()
{
	t_mlx		*param;

	param = (t_mlx *)malloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 500, 500, "fdf");
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFAAFF);
	mlx_key_hook(param->win, deal_key, param);
	//line(100, 100, 300, 50, param);
	sun(250, 250, param);
	mlx_loop(param->mlx);
	return (0);
}