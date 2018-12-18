/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:23:19 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/29 14:11:36 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	int				flag;
	unsigned char	*s;

	i = 0;
	flag = -1;
	s = (unsigned char *)str;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			flag = i;
		i++;
	}
	if (flag >= 0)
		return ((char *)&s[flag]);
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
