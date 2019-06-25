/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:00:15 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/11 19:14:57 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	const char	*p1;
	const char	*p2;
	size_t		i;

	i = 0;
	p2 = str2;
	if (*p2 == '\0')
		return ((char*)str1);
	while (*str1 != '\0')
	{
		p1 = str1;
		while (*p1 == *p2 || *p2 == '\0')
		{
			if (*p2 == '\0' && i + ft_strlen(str2) <= n)
				return ((char*)str1);
			p1++;
			p2++;
		}
		p2 = str2;
		i++;
		str1++;
	}
	return (0);
}
