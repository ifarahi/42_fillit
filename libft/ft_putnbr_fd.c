/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afasihi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:32:09 by afasihi           #+#    #+#             */
/*   Updated: 2018/10/13 14:35:33 by afasihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = n * -1;
	}
	else
		res = n;
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd(res % 10 + 48, fd);
}
