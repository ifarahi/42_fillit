/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:31:39 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/12 19:29:13 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;

	if (!(s))
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && i < len)
		len--;
	str = ft_strsub(s, i, (len - i + 1));
	return (str);
}
