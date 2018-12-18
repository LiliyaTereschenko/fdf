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
#define ABS(Value) (Value > 0) ? Value : -Value

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
}					t_mlx;

static int sign(int x)
{
	if (x > 0) 
		return (1);
	else
		return (-1);
}

static void draw_line_X(int x0, int y0, int x1, int y1, t_mlx *param)
{
	int err;
	int dx;
	int dy;
	int sgn_y;
//	int sgn_x;

	dx = ((x1 - x0) > 0) ? (x1 - x0) : (x0 - x1);
	dy = ((y1 - y0) > 0) ? (y1 - y0) : (y0 - y1);
	sgn_y = ((y1 - y0) > 0) ? 1 : -1;
//	sgn_x = sign(x1 - x0);
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
	//sgn_y = sign(y1 - y0);
	sgn_x = ((x1 - x0) > 0) ? 1 : -1;
	//sgn_x = sign(x1 - x0);
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
	/*
	int dx = x1 - x0;
	int dy = y1 - y0;
	int sgn_x = sign(dx);
	int sgn_y = sign(dy);
	int pdx;
	int pdy;
	int es;
	int el;
	int x;
	int y;

	dx = ABS(dx);
	dy = ABS(dy);
	if (dx > dy)
	{
		pdx = sgn_x;
		pdy = 0;
		el = dx;
		es = dy;
	}
	else
	{
		pdx = 0;
		pdy = sgn_y;
		el = dy;
		es = dx;
	}
	x = x0;
	y = y0;
	int err = el / 2;
	mlx_pixel_put(param->mlx, param->win, x0, y0, 0xFFAAFF);
	for (int t = 0; t < el; t++)
	{
		err -=es;
		if (err < 0)
		{
			err += el;
			x += sgn_x;
			y += sgn_y;
		}
		else
		{
			x += pdx;
			y += pdy;
		}
		mlx_pixel_put(param->mlx, param->win, x, y, 0xFFAAFF);
	}*/
}

void sun(int x0, int y0, t_mlx *param)
{
	float r = 100;
    //int x0 = 250;
   // int y0 = 250;
    int dx;
    int dy;
    for(int i = 0; i < 360; i+=5)
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