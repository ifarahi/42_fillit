/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:09:47 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/21 16:07:51 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*p;

	i = 0;
	p = (const char*)s;
	while (i < n)
	{
		if (p[i] == (char)c)
			return ((void*)p + i);
		i++;
	}
	return (NULL);
}
