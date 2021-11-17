# ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <limits.h>

int 	ft_basewrite(long n,int base, size_t index, char alpha);
int 	ft_printmemorie(size_t n, size_t index);
int     ft_isdigit(int c);
int   	ft_putchar(char c, size_t index);
int   	ft_putstr(char *s, size_t index);
char    *ft_itoa(int n);
char    *ft_utoa(unsigned int n);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *src);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_printf(const char *s,...);
#endif
