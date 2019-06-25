/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 18:36:12 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/14 13:31:05 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *str, char c)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == c)
			len = 0;
		else if (++len == 1)
			count++;
		str++;
	}
	return (count);
}
