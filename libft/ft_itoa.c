/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:37:04 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/26 17:00:33 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
		i = num_count(-n) + 1;
	else
	{
		while (n > 0)
		{
			i++;
			n /= 10;
		}
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = num_count(n) - 1;
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	if (n == -2147483648)
	{
		res[len--] = '8';
		n = -214748364;
	}
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (res);
}
