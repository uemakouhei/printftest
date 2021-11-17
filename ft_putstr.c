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
int	ft_putstr(char *s,size_t index)
{
	size_t	i;
	size_t 	size;
	
	if (s == NULL)
		s = ft_strdup("(null)\0");
	i = 0;
	size = ft_strlen(s);
	while (i != size)
	{
		if (i == INT_MAX)
			return (INT_MAX);
		i += ft_putchar(s[i],index);
		index++;
	}	
	return (size);
}
