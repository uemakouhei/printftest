#include "ft_printf.h"
#include <stdio.h>
static char	*getbasestring(int base, char alphasize)
{
	int	i;
	unsigned char 	alpha;
	char *s;

	s = (char *)malloc(sizeof(char) * (base + 1));	
	alpha = '0';
	i = -1;
	while (++i != base)
	{
		s[i] = i + alpha;
		if (i == 9 && alphasize == 'X')
			alpha = '7';
		else if (i == 9 && alphasize == 'x') 
			alpha = 'W';
	}
	s[i] = '\0';
	return (s);
}

int ft_basewrite(unsigned int n, int base, char alpha, c_out *s)
{
	char *basestr;
	char *p;
	long num;
	
	num = n;
	basestr = getbasestring(base,alpha);
	p = (char *)malloc(sizeof(char) * 17);
	if (n == 0 || p == NULL)
		return (ft_putchar('0',s));
	*p = '\0';
	while (n)
	{ 
	  	p++;	
		*p = basestr[num % base];
		num /= base;
		n /= base;
	}
	while (*p && s -> sign == 0)
		ft_putchar(*p--,s);
	return (1);
}
