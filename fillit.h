/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:49:13 by afasihi           #+#    #+#             */
/*   Updated: 2018/12/07 21:15:29 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;
typedef struct		s_tetris
{
	char			name;
	t_point			point[4];
	t_point			*max;
	struct s_tetris	*next;
}					t_tetris;

int					list_len(t_tetris *list);
t_point				*initial_p(t_point *point);
void				initial_tab(char **tab, int bord);
int					initial_bord(int len);
char				**tab_malloc(int bord);
int					ft_sqrt(int len);
void				print_shape(char **tab, int bord);
char				**increase_bord(char **tab, int bord);
t_point				*add_max(t_tetris *list);
void				remove_tetri(t_tetris *list, char **tab, t_point *hash);
void				add_shape(t_tetris *list, char **tab, t_point *hash);
int					fillit(t_tetris *list, char **tab, int bord, t_point *hash);
void				solve(t_tetris *t);
t_tetris			*ft_reading(const int fd);

#endif
