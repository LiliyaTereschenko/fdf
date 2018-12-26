/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:04:45 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/17 14:04:47 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_max_x(char *tmp)
{
	int		max_x;

	max_x = 0;
	while (*tmp)
	{
		while (*tmp == ' ')
			tmp++;
		max_x++;
		while (*tmp != ' ' && *tmp)
			tmp++;
	}
	return (max_x);
}

static void	ft_check_valid(t_list *list, int max)
{
	while (list)
	{
		if (ft_max_x(list->content) != max)
		{
			ft_putendl_fd("map is invalid", 2);
			exit(0);
		}
		list = list->next;
	}
}

static int	ft_fill_line(t_mlx *fdf, int i, t_point ***map, t_list *list)
{
	int		j;
	char	**arr;

	j = 0;
	if (!(((*map)[i]) = (t_point *)malloc(sizeof(t_point) * (fdf->max_x))))
		return (0);
	arr = ft_strsplit(list->content, ' ');
	while (j < fdf->max_x)
	{
		(*map)[i][j].x = j - (fdf->max_x) / 2;
		(*map)[i][j].y = i - (fdf->max_y) / 2;
		(*map)[i][j].z = ft_atoi(arr[j]);
		j++;
	}
	return (1);
}

static int	ft_create_matrix(t_list *begin_list, t_point ***map, t_mlx *fdf)
{
	t_list	*list;
	int		i;

	list = begin_list;
	fdf->max_y = ft_lst_size(list);
	fdf->max_x = ft_max_x(list->content);
	ft_check_valid(list, fdf->max_x);
	if (!(*map = (t_point **)malloc(sizeof(t_point *) * ((fdf->max_y)))))
		return (0);
	i = 0;
	while (list)
	{
		if (!(ft_fill_line(fdf, i, map, list)))
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

int			ft_read_map(char *file_name, t_point ***map, t_mlx *fdf)
{
	int		fd;
	char	*line;
	t_list	*l;
	t_list	*begin;

	begin = NULL;
	l = NULL;
	if (!(fd = open(file_name, O_RDONLY)))
		return (0);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!(l = ft_lstnew(line, sizeof(char) * ft_strlen(line))))
				return (0);
			else
				ft_lst_push_back(&begin, l);
		}
	}
	close(fd);
	if (!ft_create_matrix(begin, map, fdf))
		return (0);
	return (1);
}
