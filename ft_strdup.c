/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:05:36 by kuema             #+#    #+#             */
/*   Updated: 2021/11/07 01:00:34 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(src);
	if (src == NULL)
		return (NULL);
	if (*src == '\0')
		size = 0;
	ptr = (char *)malloc(ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	if (ptr)
	{
		ft_strlcpy(ptr, src, size + 1);
	}
	return (ptr);
}
