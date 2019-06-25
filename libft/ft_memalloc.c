/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:50:36 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/11 19:08:17 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
