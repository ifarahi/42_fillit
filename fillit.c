/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:45:47 by afasihi           #+#    #+#             */
/*   Updated: 2018/12/07 20:55:08 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_point	*test_place(t_tetris *list, char **tab, int bord, t_point *hash)
{
	int	i;

	if (list->max->x + hash->x >= bord || list->max->y + hash->y > bord)
		return (NULL);
	if (list->max->y + hash->y == bord)
	{
		hash->y = 0;
		hash->x++;
	}
	i = 0;
	while (i < 4)
	{
		if (tab[list->point[i].x + hash->x][list->point[i].y + hash->y] != '.')
		{
			hash->y++;
			return (test_place(list, tab, bord, hash));
		}
		i++;
	}
	return (hash);
}

void	add_shape(t_tetris *list, char **tab, t_point *hash)
{
	int		i;
	char	c;

	i = 0;
	c = list->name;
	while (i < 4)
	{
		tab[list->point[i].x + hash->x][list->point[i].y + hash->y] = c;
		i++;
	}
}

int		fillit(t_tetris *list, char **tab, int bord, t_point *hash)
{
	t_point	*fresh;

	fresh = (t_point*)malloc(sizeof(t_point) * 1);
	fresh->x = 0;
	fresh->y = 0;
	if (list == NULL)
	{
		print_shape(tab, bord);
		exit(1);
	}
	if ((hash = test_place(list, tab, bord, hash)) != NULL)
	{
		add_shape(list, tab, hash);
		if (fillit(list->next, tab, bord, fresh) == 0)
		{
			remove_tetri(list, tab, hash);
			hash->y++;
			if (!fillit(list, tab, bord, hash))
				return (0);
		}
	}
	return (0);
}

void	solve(t_tetris *t)
{
	int		bord;
	char	**tab;
	t_point	*hash;

	hash = (t_point*)malloc(sizeof(t_point) * 1);
	hash = initial_p(hash);
	bord = initial_bord(list_len(t));
	tab = tab_malloc(bord);
	initial_tab(tab, bord);
	while (fillit(t, tab, bord, hash) == 0)
	{
		bord++;
		initial_tab(tab, bord);
		hash = initial_p(hash);
		tab = increase_bord(tab, bord);
	}
}
