/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:54:27 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/04 17:31:26 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_line(char **line, char *s)
{
	char *str;

	str = ft_strchr(s, '\n');
	if (str)
	{
		str[0] = '\0';
		*line = ft_strdup(s);
		ft_memmove(s, &str[1], ft_strlen(&str[1]) + 1);
		return (1);
	}
	else if (ft_strlen(s) > 0)
	{
		*line = ft_strdup(s);
		*s = 0;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *s[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	ret = 1;
	if (fd < 0 || !line || fd >= MAX_FD || BUFF_SIZE <= 0)
		return (-1);
	if (!s[fd])
	{
		if (!(s[fd] = ft_strnew(0)))
			return (-1);
	}
	else
		s[fd] = ft_strjoin(s[fd], "");
	while (ft_strchr(s[fd], '\n') == NULL && ret > 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		temp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = temp;
	}
	return (fill_line(line, s[fd]));
}
