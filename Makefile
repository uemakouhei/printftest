SRCS    =    ft_printf.c ft_putstr.c ft_putchar.c ft_strchr.c ft_strlen.c ft_isdigit.c ft_basewrite.c ft_printmemorie.c ft_putnbr.c ft_putunbr.c ft_fieldmake.c ft_memset.c

BONUS = ft_lstsize.c

OBJS    = $(SRCS:%.c=%.o)

BNS_OBJS = $(BONUS:%.c=%.o)

ifdef WITH_BONUS
	OBJS +=  $(BNS_OBJS)
endif
CC      = gcc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror

NAME    = libftprintf.a

all     : $(NAME)

%.o     : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean   :
	$(RM) $(OBJS) $(BNS_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      : fclean all

bonus:
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus
