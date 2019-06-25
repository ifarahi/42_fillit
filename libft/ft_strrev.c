/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:53:58 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/12 18:55:53 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	strtmp;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	len = len - 1;
	i = 0;
	while (i < ((len + 1) / 2))
	{
		strtmp = str[i];
		str[i] = str[len - i];
		str[len - i] = strtmp;
		i++;
	}
	return (str);
}
