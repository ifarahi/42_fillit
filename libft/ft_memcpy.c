/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:25:04 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/18 12:29:33 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	str1 = (char*)dest;
	str2 = (const char*)src;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
