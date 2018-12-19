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
}				t_mlx;

int             ft_read_map(char *file_name, t_point ***map);
void			line(int x0, int y0, int x1, int y1, t_mlx *param);
void			ft_draw_figure(t_point **map, t_mlx *param);



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void           printFromHead(t_list *list);
void           ft_print_map(t_point **map);

#include <stdio.h> 
#include <unistd.h>
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#endif
