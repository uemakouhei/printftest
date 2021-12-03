/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:39:19 by kuema             #+#    #+#             */
/*   Updated: 2021/11/02 16:39:21 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	*ft_memset(void *buf, int ch, size_t len)
{
	unsigned char	*pt;

	pt = (unsigned char *)buf;
	while (len-- != 0)
		*(pt++) = (unsigned char)ch;
	return (buf);
}
