/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:28:26 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/04 16:30:52 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*str;

	if (min >= max)
	{
		str = NULL;
		return (str);
	}
	if (!(str = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (max >= min)
	{
		str[max - min - 1] = max - 1;
		max--;
	}
	return (str);
}
