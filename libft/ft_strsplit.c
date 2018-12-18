/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:50:37 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/23 16:13:03 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_words_counter(char const *str, char c)
{
	int i;
	int chr;

	if (*str == '\0')
		return (0);
	i = 0;
	chr = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			chr = 0;
		}
		else
		{
			if (chr == 0)
				i++;
			chr = 1;
			str++;
		}
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s || !(tab = (char **)malloc(sizeof(*tab) *
					(ft_words_counter(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_words_counter(s, c))
	{
		k = 0;
		if (!(tab[i] = ft_strnew(word_len(&s[j], c) + 1)))
			tab[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
