/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:16:57 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/18 13:30:47 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return (dest1 + i + 1);
		i++;
	}
	return (0);
}
