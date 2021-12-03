#include "ft_printf.h"

int ft_printmemorie(size_t n, c_out *s)
{
        char *p;
        int i;

        i = -1;
        if (n == 0)
                return (s -> index += write (1,"0x0",3));
        p = (char *)malloc(sizeof(char) * 17);
	if (p == NULL)
		return (0);
        p[++i] = '\0';
        while (n != 0) //16 
        {
                p[++i] = "0123456789abcdef"[(n % 16)];
                n /= 16;
        }
        p[++i] = 'x';
        p[++i] = '0';
        p = p + i;
        while(*p != '\0' && s -> flag == 0)
                ft_putchar(*p--, s);
        return (i);
}
