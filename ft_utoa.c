#include "ft_printf.h"
char    *ft_utoa(unsigned int n)
{
	int		mallocsize;
	char		*str;
	unsigned int	tmpnum;

	tmpnum = n;
	mallocsize = 0;
	if (n == 0)
		return(ft_strdup("0"));
	while (n > 0)
	{
		n /= 10;
		mallocsize++;
	}
	str = (char *)malloc(sizeof(char) * (mallocsize + 1));
	if (str == NULL)
		return (NULL);
	str[mallocsize + 1] = '\0';
	while (tmpnum > 9 && mallocsize)
	{
		str[--mallocsize] = '0' + (tmpnum % 10);
		tmpnum = tmpnum / 10;
	}
	str[--mallocsize] = '0' + tmpnum;
	return (str);
}
