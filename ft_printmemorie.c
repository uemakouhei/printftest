#include "ft_printf.h"

int ft_printmemorie(size_t n, size_t index)
{
        char *p;
        int i;

        i = -1;
        if (n == 0)
                return (write (1,"0x0",3));
        p = (char *)malloc(sizeof(char) * 17);
        p[++i] = '\0';
        while (n != 0)
        {
                p[++i] = "0123456789abcdef"[(n % 16)];
                n /= 16;
        }
        p[++i] = 'x';
        p[++i] = '0';
        p = p + i;
        while(*p && index++ != INT_MAX)
                write(1, p--, 1);
	if (index > INT_MAX)
                return (INT_MIN);
        return (i);
}
