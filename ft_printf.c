#include "ft_printf.h"
#include <stdio.h>
static void cout_init(c_out *s)
{
	s -> sign = 0;
	s -> fmt = 0;
	s -> after = 0;
	s -> fmtsize = 0;
	s -> flag = 0;
	s -> index = 0;
}

static int formatcheck(const char *str, c_out *s, va_list list)
{
	if (ft_strchr("isdpxXuc%",*str))
	{
		s -> after = 0;
		if (*str == 's')
			ft_putstr(va_arg(list,char*),s);
		else if (*str  == 'c')
                        ft_putchar(va_arg(list,int),s);
		else if (*str == 'd' || *str == 'i')
			ft_putnbr(va_arg(list,int),s);
		else if (*str == 'p')
			ft_printmemorie(va_arg(list,size_t),s);
		else if (*str  == 'u')
                        ft_putunbr(va_arg(list,unsigned int),s);
		else if (*str  == '%')
			ft_putchar(37,s);
		else if (*str == 'x')
			ft_basewrite(va_arg(list,int),16,'x',s);
		else if (*str == 'X')
			 ft_basewrite(va_arg(list,int),16,'X',s);	
	}
	return (1);
}
//static int flagcheck(const char *str, c_out *s)
//{
//	size_t digit;
//
//	digit = 0;
//	if (ft_strchr("#-+ 0",*str))
//	{
//		if (*str++ == '#')
//			s -> flag = '#';	
//		else if (*str == '-') 
//			s -> flag = '-';	
//		else if (*str == '+')
//			s -> flag = '+';
//		else if (*str == ' ')
//			s -> flag = ' ';
//		else if (*str == '0')
//			s -> flag = '0';
//		str++;
//	}
//	digit = ft_fieldmake(str,s);
//	if (s -> flag != 0)
//		return (1 + digit);
//	return (digit);
//}
static int doprint(const char *s,va_list list)
{
	c_out cout;

	cout_init(&cout);
	while (*s != '\0')
	{
		if (cout.sign == 1)
			return (-1);
		if(*s == '%')
		{
			s++;
			//s += flagcheck(s,&cout);
			s += formatcheck(s,&cout,list);
		}
		else
			ft_putchar(*s++,&cout);
	}
	return (cout.index);
}

int ft_printf(const char *s, ...)
{
	va_list		list;
	int            returnsize;

	returnsize = 0;
	va_start(list, s);
	if (s != NULL)
		returnsize = doprint(s,list);
	va_end(list);
	return (returnsize);
}
