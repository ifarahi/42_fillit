/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:09:48 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/13 12:41:48 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(j, s[i]);
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
