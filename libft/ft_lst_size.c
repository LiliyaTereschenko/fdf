/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:47:26 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/10 18:47:27 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_size(t_list *begin_list)
{
	int k;

	k = 1;
	if (!begin_list)
		return (0);
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		k++;
	}
	return (k);
}
