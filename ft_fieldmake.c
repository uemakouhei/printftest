#include "ft_printf.h"
#include <stdio.h>
int ft_fieldmake(const char *c,c_out *s)
{
        size_t len;
        size_t tmp;

        tmp = 0;
        len = 0;
	if (*c == '\0')
		return (0);
        while(ft_isdigit(*c))
        {
                len = 10 * ((*c - '0') + len);
                c++;
                tmp++;
        }
	len /= 10;
	s->fmtsize = len;
	s->fmt = (char *)malloc(sizeof(char) * len);
	if (s->sign == '0')
		ft_memset(s->fmt,'0',len);
	else
		ft_memset(s->fmt,' ',len);	
	return (tmp);
}
