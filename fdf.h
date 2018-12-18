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
# define BUFF_SIZE 32

typedef struct	s_point
{
	int         z;
	char        *color;
}				t_point;


void            ft_print_map(char **map);
int             ft_read_map(char *file_name, t_point ***map);




void           printFromHead(t_list *list);
#include <stdio.h> //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#endif
