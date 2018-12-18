/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:05:52 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/26 18:26:16 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	destlen;

	d = (char *)dest;
	s = (char *)src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	destlen = d - dest;
	n = size - destlen;
	if (n == 0)
		return (destlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (destlen + (s - src));
}
