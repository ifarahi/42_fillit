/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:51:16 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/11 12:04:14 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	const char *p1;
	const char *p2;

	p2 = str2;
	if (*p2 == '\0')
		return ((char*)str1);
	while (*str1 != '\0')
	{
		if (*str1 == *p2)
		{
			p1 = str1;
			while (*p1 == *p2 || *p2 == '\0')
			{
				if (*p2 == '\0')
					return ((char*)str1);
				p1++;
				p2++;
			}
			p2 = str2;
		}
		str1++;
	}
	return (0);
}
