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

static int size_return(unsigned int n)
{
	int size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}
int	ft_putunbr(unsigned int n,c_out *s)
{
	if (s->flag == 0)
	{
		if (n > 9)
		{
			ft_putnbr(n / 10,s);
		}
		ft_putchar('0' + n % 10,s);
	}
	return (size_return(n));
}
