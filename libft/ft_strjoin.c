/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:36:49 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/22 20:00:00 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!res)
		return (NULL);
	res = ft_strcat(ft_strcat(res, (char *)s1), (char *)s2);
	return (res);
}
