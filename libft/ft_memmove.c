/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:37:38 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/11 15:22:19 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;
	char		tmp[65534];

	if (n >= 65535)
		return (0);
	dest = (char*)str1;
	src = (char*)str2;
	i = 0;
	while (i < n)
	{
		tmp[i] = src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}
