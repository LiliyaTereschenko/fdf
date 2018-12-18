/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:55:43 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/13 15:18:37 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_pretail(t_list **begin_list)
{
	t_list *l;
	t_list *tmp;

	l = *begin_list;
	tmp = l;
	while (l->next)
	{
		tmp = l;
		l = l->next;
	}
	return (tmp);
}

void			ft_lst_del_last(t_list **begin_list)
{
	t_list *tail;
	t_list *tmp;
	t_list *for_free;
	t_list *pretail;

	if ((pretail = ft_pretail(begin_list)))
	{
		tail = ((pretail->next)) ? pretail->next : pretail;
		tmp = tail->content;
		while (tmp)
		{
			for_free = tmp->next;
			tmp = NULL;
			tmp = for_free;
		}
		tail->content = NULL;
		if (!pretail->next)
			pretail->content = NULL;
		tail = NULL;
		if (pretail->next)
			pretail->next = NULL;
		else
			*begin_list = NULL;
	}
}
