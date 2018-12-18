/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:16:59 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 12:17:02 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin_list, t_list *new)
{
	t_list *current;

	current = *begin_list;
	if (!current)
	{
		*begin_list = new;
		(*begin_list)->next = NULL;
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
}
