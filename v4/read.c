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
	int	max_x;

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

static int	ft_create_matrix(t_list *begin_list, t_point ***map, t_mlx *fdf)
{
	t_list	*list;
	//int		max_x;
	//int		max_y;
	int		i;
	int		j;
	char	**arr;

	list = begin_list;
	fdf->max_Y = ft_lst_size(list);
	fdf->max_X = ft_max_x(list->content);

	if (!(*map = (t_point **)malloc(sizeof(t_point *) * ((fdf->max_Y)))))
		return (0);
	if (!((fdf->map_tmp) = (t_point **)malloc(sizeof(t_point *) * ((fdf->max_Y)))))
		return (0);
	if (!(*map[0] = (t_point *)malloc(sizeof(t_point))))
			return (0);
	if (!((fdf->map_tmp)[0] = (t_point *)malloc(sizeof(t_point))))
			return (0);
	//(*map)[0][0].x = fdf->max_X;
	//(*map)[0][0].y = fdf->max_Y;
	i = 0;
	while (list)
	{	
		j = 0;
		if (!(((*map)[i]) = (t_point *)malloc(sizeof(t_point) * (fdf->max_X))))
			return (0);
		if (!(((fdf->map_tmp)[i]) = (t_point *)malloc(sizeof(t_point) * (fdf->max_X))))
			return (0);
		arr = ft_strsplit(list->content, ' ');
		
		while (j < fdf->max_X)
		{
			(*map)[i][j].x = j - (fdf->max_X) / 2;
			(*map)[i][j].y = i - (fdf->max_Y) / 2;
			(*map)[i][j].z = ft_atoi(arr[j]);
			j++;
		}
		list = list->next;
		i++;
	}
	printf("malloc for matrix - " GREEN "done" RESET "\n");
	printf("matrix full - " GREEN "done" RESET "\n");
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
	{
		ft_putendl_fd("error open file", 2);
		return (0);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			//printf("line = %s\n", line);
			if (!(l = ft_lstnew(line, sizeof(char) * ft_strlen(line))))
				return (0);
			else
				ft_lst_push_back(&begin, l);
		}
	}
	printf("list of lines - " GREEN "done" RESET "\n");
	close(fd);
	if (!ft_create_matrix(begin, map, fdf))
		return (0);
	return (1);
}
