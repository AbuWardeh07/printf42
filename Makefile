NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c \
       ft_printchar.c \
       ft_printstr.c \
       ft_printptr.c \
       ft_printnbr.c \
       ft_printunsigned.c \
       ft_printhex.c \
       ft_print_hel.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :	
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
