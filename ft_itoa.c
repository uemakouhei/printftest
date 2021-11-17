/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:54:05 by kuema             #+#    #+#             */
/*   Updated: 2021/11/04 19:26:32 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	putitoa(int n, int digit, char *str)
{
	str[digit] = '\0';
	digit--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		if (n < 10)
		{
			str[digit] = 48 + n;
			break ;
		}
		str[digit] = 48 + (n % 10);
		n = n / 10;
		digit--;
	}
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;
	int		n2;

	n2 = n;
	digit = 0;
	if (n == -2147483648)
		return(ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0 && digit++ != 1)
		n2 = n2 * -1;
	while (n2 > 0 && digit++ != 12)
		n2 /= 10;
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (str == NULL)
		return (NULL);
	putitoa(n, digit, str);
	return (str);
}
