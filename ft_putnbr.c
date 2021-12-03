/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:08:01 by kuema             #+#    #+#             */
/*   Updated: 2021/11/04 07:17:13 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n,c_out *s)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10,s);
		ft_putchar('0' - n % 10,s);
	}
	else if (n < 0)
	{
		ft_putchar('-',s);
		ft_putnbr(n *= -1,s);
	}
	else if (s -> flag == 0)
	{
		if (n > 9)
		{
			ft_putnbr(n / 10,s);
		}
		ft_putchar('0' + n % 10,s);
	}
	return (1);
}
