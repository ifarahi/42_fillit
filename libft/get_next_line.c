/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:25:38 by afasihi           #+#    #+#             */
/*   Updated: 2018/11/21 15:02:34 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_newline(const int fd, char **str, char **line)
{
	int i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		str[fd] = ft_strdup(str[fd] + i + 1);
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*cont[4096];

	if (fd < 0 || line == NULL || fd > 4096)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (cont[fd] == NULL)
			cont[fd] = ft_strnew(1);
		cont[fd] = ft_strjoin(cont[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && (cont[fd] == NULL || cont[fd][0] == '\0'))
		return (0);
	return (ft_newline(fd, cont, line));
}
