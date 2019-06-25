/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:18:30 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/11 11:54:08 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 == *str2 && *str2 != '\0' && *str1 != '\0' && n)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*str1 - (unsigned char)*str2);
}
