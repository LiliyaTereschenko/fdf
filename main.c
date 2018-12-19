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
	// t_mlx	*param;
	// int t = 250;
	// int m = 700;
	
	map = NULL;
	if (argc == 2)
	{
		if ((ft_read_map(argv[1], &map)))
		{
			ft_print_map(map);
			// printf(GREEN "success" RESET "\n");
			// param = (t_mlx *)malloc(sizeof(t_mlx));
			// param->mlx = mlx_init();
			// param->win = mlx_new_window(param->mlx, m, m, "fdf");
			// mlx_key_hook(param->win, deal_key, param);
			// line(t, t, m - t, t, param);
			// line(t, m - t, m - t, m - t, param);
			// line(t, t, t, m - t, param);
			// line(m - t, t, m - t, m - t, param);
			// //sun(350, 350, param);
			// mlx_loop(param->mlx);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fdf file_name\n");
	return (0);
}
