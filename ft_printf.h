# ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
typedef struct {
	size_t index;
	int flag;
	char *fmt;
	size_t fmtsize;
	int sign;
	int after;
}c_out;

void    *ft_memset(void *buf, int ch, size_t len);
int     ft_putunbr(unsigned int n, c_out *s);
int 	ft_printmemorie(size_t n, c_out *s);
int     ft_isdigit(int c);
int   	ft_putchar(char c, c_out *s);
int   	ft_putstr(char *str,c_out *s);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
int	ft_printf(const char *s,...);
int    ft_putnbr(int n, c_out *s);
void    ft_putnbr_base(int nbr, char *base,c_out *s);
int ft_basewrite(unsigned int n, int base, char alpha, c_out *s);
#endif
