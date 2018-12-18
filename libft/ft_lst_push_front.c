/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:15:25 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/17 19:22:20 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_front(t_list **begin_list, t_list *new)
{
	if (*begin_list)
	{
		new = ft_lstnew(new->content, new->content_size);
		new->next = *begin_list;
		*begin_list = new;
	}
	else
		*begin_list = ft_lstnew(new->content, new->content_size);
}

