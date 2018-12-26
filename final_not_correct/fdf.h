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
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			win_size_x;
	int			win_size_y;
	int			start_x;
	int			start_y;
	int			max_x;
	int			max_y;
	t_point		**map;
	t_point		**map_tmp;
	float		ang_x;
	float		ang_y;
	float		ang_z;
	int			zoom;
}				t_mlx;

void			print_menu(t_mlx *fdf);
int				ft_press_key(int key, t_mlx *fdf);
void			ft_key(int key, t_mlx *fdf);
int				ft_make_copy(t_mlx *fdf);
int				ft_read_map(char *file_name, t_point ***map, t_mlx *fdf);
void			line(t_line *l, t_mlx *fdf);
void			ft_draw_figure(t_point **map, t_mlx *fdf);
void			ft_change_matrix(t_mlx *fdf);

#endif
