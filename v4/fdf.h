/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:07:28 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/17 14:07:36 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h> 


# define BUFF_SIZE 32

typedef struct	s_point
{
	int 		x;
	int			y;
	int         z;
	int        	color;
}				t_point;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			win_size_x;
	int			win_size_y;
	int			start_X;
	int			start_Y; 
	int			max_X;
	int			max_Y;
	t_point		**map;
	t_point		**map_tmp;
	float		ang_X;
	float		ang_Y;
	float		ang_Z;
	int			zoom;

}				t_mlx;


int				ft_press_key(int key, t_mlx *fdf);
void			ft_key(int key, t_mlx *fdf);
void			ft_make_copy(t_mlx *fdf);
int             ft_read_map(char *file_name, t_point ***map, t_mlx *fdf);
void			line(int x0, int y0, int x1, int y1, t_mlx *fdf);
void			ft_draw_figure(t_point **map, t_mlx *fdf);
void			ft_change_matrix(t_mlx *fdf);



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void           ft_print_map(t_point **map, t_mlx *fdf);

#include <stdio.h> 
#include <unistd.h>
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#endif
