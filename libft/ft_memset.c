/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:11:34 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/26 17:04:26 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (dest);
}
