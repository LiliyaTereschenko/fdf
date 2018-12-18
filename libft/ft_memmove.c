/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:26:04 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/26 17:06:52 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (s < d)
	{
		s = s + len - 1;
		d = d + len - 1;
		while (len > 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	return (dst);
}
