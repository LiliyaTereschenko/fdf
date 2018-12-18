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

static int	ft_create_matrix(t_list *begin_list, t_point ***map)
{
	t_list	*list;
	int		max_x;
	int		max_y;
	int		i;
	char	**arr;

	list = begin_list;
	max_y = ft_lst_size(list);
	max_x = ft_max_x(list->content);

	printf("max_x = %d\n", max_x);
	printf("max_y = %d\n", max_y); 

	if (!(*map = (t_point **)malloc(sizeof(t_point *) * max_y)))
		return (0);
	while (list)
	{
		if (!(**map = (t_point *)malloc(sizeof(t_point) * max_x)))
			return (0);
		arr = ft_strsplit(list->content, ' ');
		i = 0;
		while (i < max_x)
		{
			(**map)[i].z = ft_atoi(arr[i]);
			//printf("%d ", (**map)[i].z);
			i++;
		}
		//printf("\n");
		list = list->next;
	}
	printf("malloc for matrix - " GREEN "done" RESET "\n");
	printf("matrix full - " GREEN "done" RESET "\n");
	return (1);
}

int			ft_read_map(char *file_name, t_point ***map)
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
	//printFromHead(begin);
	printf("list of lines - " GREEN "done" RESET "\n");
	close(fd);
	if (!ft_create_matrix(begin, map))
		return (0);
	return (1);
}
