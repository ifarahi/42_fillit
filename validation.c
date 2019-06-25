/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:02:16 by ifarahi           #+#    #+#             */
/*   Updated: 2018/12/07 21:05:39 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_loading_tetri(char **line, t_tetris *tetris)
{
	int			i;
	int			j;
	t_point		min;

	i = -1;
	j = -1;
	min.x = 4;
	min.y = 4;
	while (++i < 16)
	{
		if (line[i / 4][i % 4] == '#')
		{
			tetris->point[++j].x = i / 4;
			tetris->point[j].y = i % 4;
			min.x = (min.x > tetris->point[j].x) ? tetris->point[j].x : min.x;
			min.y = (min.y > tetris->point[j].y) ? tetris->point[j].y : min.y;
		}
	}
	j = -1;
	while (++j < 4)
	{
		tetris->point[j].x -= min.x;
		tetris->point[j].y -= min.y;
	}
	tetris->max = add_max(tetris);
}

int			ft_bloc(char **line, int i, int j)
{
	int		nb;

	nb = 0;
	if (i - 1 >= 0)
		if (line[i - 1][j] == '#')
			nb++;
	if (j - 1 >= 0)
		if (line[i][j - 1] == '#')
			nb++;
	if (i + 1 <= 3)
		if (line[i + 1][j] == '#')
			nb++;
	if (j + 1 <= 3)
		if (line[i][j + 1] == '#')
			nb++;
	return (nb);
}

int			ft_is_valide(char **line)
{
	int		empty;
	int		bloc;
	int		i;
	int		cnx;

	i = 0;
	empty = 0;
	bloc = 0;
	cnx = 0;
	while (i < 16)
	{
		if (line[i / 4][i % 4] == '.')
			empty++;
		else if (line[i / 4][i % 4] == '#')
		{
			cnx += ft_bloc(line, i / 4, i % 4);
			bloc++;
		}
		else
			return (0);
		i++;
	}
	if (bloc != 4 || empty != 12 || (cnx != 6 && cnx != 8))
		return (0);
	return (1);
}

int			ft_reading_tetri(const int fd, t_tetris *list)
{
	int		i;
	int		ret;
	char	*line[5];

	if (get_next_line(fd, &line[0]) == 0 || (ft_strlen(line[0]) != 4))
		return (-1);
	i = 0;
	while (++i < 4)
	{
		if ((get_next_line(fd, &line[i]) == 0) || ft_strlen(line[i]) != 4)
			return (-1);
	}
	if ((ret = get_next_line(fd, &line[4])) == 0 || (ft_strlen(line[4]) == 0))
	{
		if (ft_is_valide(line))
			ft_loading_tetri(line, list);
		else
			return (-1);
		if (ret == 1 && ft_strlen(line[4]) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}

t_tetris	*ft_reading(const int fd)
{
	t_tetris	*list;
	t_tetris	*ptr;
	char		a;
	int			ret;

	a = 'A';
	if (!(ptr = ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	list = ptr;
	while ((ret = ft_reading_tetri(fd, ptr)) >= 0)
	{
		ptr->name = a++;
		if (ret == 0)
			return (list);
		ptr->next = ft_memalloc(sizeof(t_tetris));
		ptr = ptr->next;
	}
	return (NULL);
}
