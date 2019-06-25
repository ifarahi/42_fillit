/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:57:33 by afasihi           #+#    #+#             */
/*   Updated: 2018/12/07 21:03:10 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void		remove_list(t_tetris *list)
{
	t_tetris	*tetris;

	if (list == NULL)
		return ;
	tetris = list;
	while (list)
	{
		list = list->next;
		free(tetris);
		tetris = list;
	}
}

int			main(int argc, char **argv)
{
	int			fd;
	t_tetris	*tetris;

	tetris = ft_memalloc(sizeof(t_tetris));
	if (argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" tetris_list_file\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(tetris = ft_reading(fd)) || list_len(tetris) > 26)
	{
		remove_list(tetris);
		ft_putendl("error");
		exit(1);
	}
	close(fd);
	solve(tetris);
	remove_list(tetris);
	return (0);
}
