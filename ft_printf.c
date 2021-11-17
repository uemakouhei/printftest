#include "ft_printf.h"
#include <stdio.h>
static size_t fragformatcheck(const char *c,va_list list,long index)
{
	if (*c == 's')
		return (ft_putstr(va_arg(list,char*),index));
	else if (*c == 'd' || *c == 'i')
		return (ft_putstr(ft_itoa(va_arg(list,int)),index));	
	else if (*c== 'p')
		return (ft_printmemorie(va_arg(list,size_t),index));
	else if (*c== 'x')
		return(ft_basewrite(va_arg(list,size_t),16,index,'a'));
	else if (*c == 'u')
		return(ft_putstr(ft_utoa(va_arg(list,unsigned int)),index));
	else if (*c == 'c')
		return (ft_putchar(va_arg(list,int),index));
	else if (*c == 'X')
		return (ft_basewrite(va_arg(list,size_t),16,index,'A'));
	else if (*c == '%')
		return(ft_putchar(37,index));
	return (0);
}

int ft_printf(const char *s, ...)
{
	va_list		list;
	size_t		index;
	size_t 		start; 
	long	returnsize;

	returnsize = 0;
	start = 0;
	index = 0;
	va_start(list, s);
	while (s[index] != '\0')
	{
		if (returnsize > INT_MAX)
			return(-1);	
		if(s[index] == '%')
		{
			returnsize += ft_putstr(ft_substr(s,start,index++ - start),returnsize);
			if (ft_strchr("cspdiuxX%",s[index]) || ft_isdigit(s[index]))
				returnsize += fragformatcheck(s + index,list,returnsize);
			start += ++index - start;
		}
		else
			index++;
	}
	returnsize += ft_putstr(ft_substr(s,start,index - start),returnsize);
	va_end(list);
	return (returnsize);
}
