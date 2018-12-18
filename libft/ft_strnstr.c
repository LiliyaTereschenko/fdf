/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:17:53 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/29 12:09:35 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	const char	*h;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && len > 0)
	{
		if (*s1 == *s2)
		{
			h = s1;
			while (*s1++ == *s2++)
			{
				if (*s2 == 0 && len >= (unsigned int)s1 - (unsigned int)h)
					return ((char *)h);
			}
			s2 -= s1 - h;
			s1 = h;
		}
		len--;
		s1++;
	}
	return (NULL);
}
