/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:06:51 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/11 19:10:47 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int sign;
	int rest;

	i = 0;
	sign = 1;
	rest = 0;
	while ((str[i] < 14 && str[i] > 7) || str[i] == ' ')
		i++;
	if ((str[i] == '+' && str[i + 1] == '-') ||
			(str[i] == '-' && str[i + 1] == '+'))
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + str[i] - '0';
		i++;
	}
	return (rest * sign);
}
