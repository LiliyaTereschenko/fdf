/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:50:49 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 12:51:02 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int k;

	k = 0;
	if (!begin_list)
		return (NULL);
	while (k < nbr && begin_list)
	{
		begin_list = begin_list->next;
		k++;
	}
	if (k < nbr)
		return (NULL);
	else
		return (begin_list);
}
