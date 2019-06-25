/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:20:51 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/17 18:18:27 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dest);
	k = ft_strlen(src);
	if (n == 0)
		return (k);
	if (i > n)
		k = k + n;
	else
		k = k + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (k);
}
