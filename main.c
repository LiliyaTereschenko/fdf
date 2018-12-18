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
}
