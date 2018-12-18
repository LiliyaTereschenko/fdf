/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:50:59 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/29 16:28:22 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	int				neg;
	int				i;
	long long int	num;
	long long int	temp;

	neg = 0;
	i = 0;
	num = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\v' ||
			s[i] == '\f' || s[i] == '\n')
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		temp = num;
		num *= 10;
		num += ((int)s[i] - '0');
		if (num < temp)
			return (neg == 1 ? 0 : -1);
		i++;
	}
	return (neg == 1 ? -num : num);
}
