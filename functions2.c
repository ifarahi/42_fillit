/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:10:26 by afasihi           #+#    #+#             */
/*   Updated: 2018/12/06 17:36:50 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int len)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (len == 0 || len == 1)
		return (len);
	while (res <= len)
	{
		i++;
		res = i * i;
	}
	return (i - 1);
}

void	print_shape(char **tab, int bord)
{
	int	i;

	i = 0;
	while (i < bord)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

char	**increase_bord(char **tab, int bord)
{
	free(tab);
	tab = tab_malloc(bord);
	initial_tab(tab, bord);
	return (tab);
}

t_point	*add_max(t_tetris *list)
{
	int		i;
	t_point	*max;

	i = 0;
	max = (t_point*)malloc(sizeof(t_point) * 1);
	max->x = 0;
	max->y = 0;
	while (i < 4)
	{
		if (list->point[i].x > max->x)
			max->x = list->point[i].x;
		if (list->point[i].y > max->y)
			max->y = list->point[i].y;
		i++;
	}
	return (max);
}

void	remove_tetri(t_tetris *list, char **tab, t_point *hash)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab[list->point[i].x + hash->x][list->point[i].y + hash->y] = '.';
		i++;
	}
}
