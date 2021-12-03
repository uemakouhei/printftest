/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:59:51 by kuema             #+#    #+#             */
/*   Updated: 2021/11/05 01:22:54 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_putstr(char *str,c_out *s)
{
	size_t index;

	index = 0;
	if (str == NULL)
		return (s -> index += write(1,"(null)",6));
	while (str[index] != '\0' && s -> sign == 0)
	{
		ft_putchar(str[index],s);
		index++;
	}
	return (1);
}
