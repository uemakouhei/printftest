#include "ft_printf.h"
static char	*getbasestring(int base, char alphasize)
{
	int	i;
	unsigned char 	alpha;
	char *s;

	s = (char *)malloc(sizeof(char) * (base + 1));	
	alpha = '0';
	i = -1;
	while (i != base)
	{
		s[i] = i + alpha;
		if (i == 9 && alphasize == 'A')
			alpha = '7';
		else if (i == 9 && alphasize == 'a') 
			alpha = 'W';
		i++;
	}
	s[i] = '\0';
	return (s);
}

int ft_basewrite(long n, int base, size_t index, char alpha)
{
	char *s;
	char *p;
	size_t i;

	i = -1;	
	s = getbasestring(base,alpha);
	p = (char *)malloc(sizeof(char) * 17);
	if (n == 0)
		return (write(1,"0",1));
	p[++i] = '\0';
	while (n)
	{       
		p[++i] = s[n % base];
		n /= base;
	} 
	p = p + i;
	while(*p && index++ != INT_MAX)
		write(1, p--, 1);
	if (index > INT_MAX)
		return (INT_MIN);
	else
		return (i);	
}
