/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:11:07 by afasihi           #+#    #+#             */
/*   Updated: 2018/12/06 15:39:51 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		list_len(t_tetris *list)
{
	int		len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

t_point	*initial_p(t_point *point)
{
	point->x = 0;
	point->y = 0;
	return (point);
}

void	initial_tab(char **tab, int bord)
{
	int	i;
	int	j;

	i = 0;
	while (i < bord)
	{
		j = 0;
		while (j < bord)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
}

int		initial_bord(int len)
{
	int	bord;

	bord = ft_sqrt(len * 4);
	if (len > 22)
		return (11);
	else if (len > 18)
		return (10);
	else if (len > 14)
		return (9);
	return (bord);
}

char	**tab_malloc(int bord)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * bord + 1);
	while (i <= bord)
	{
		tab[i] = (char*)malloc(sizeof(char*) * bord);
		i++;
	}
	return (tab);
}
