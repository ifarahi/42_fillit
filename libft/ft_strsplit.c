/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:25:29 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/14 13:32:42 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	if (!(s))
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * ft_countwords(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > len)
			tab[j++] = ft_strndup(s + len, i - len);
	}
	tab[j] = NULL;
	return (tab);
}
