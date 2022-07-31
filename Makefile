SRCS	= ft_printf.c \
		  src/parse/ft_parse_chr.c \
		  src/parse/ft_parse_hex.c \
		  src/parse/ft_parse_int.c \
		  src/parse/ft_parse_ptr.c \
		  src/parse/ft_parse_str.c \
		  src/parse/ft_parse_uint.c \
		  src/putnbr/ft_puthex_fd.c \
		  src/putnbr/ft_putint_fd.c \
		  src/putnbr/ft_putptr_fd.c \
		  src/putnbr/ft_putuint_fd.c
OBJS	= ${SRCS:.c=.o}
INCD	= ./
NAME	= libftprintf.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

%.o:		${SRCS}%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

test:	${NAME}
			gcc -L./ test_src/printf.c -lcriterion -lpthread -lftprintf -o test.out && ./test.out && rm test.out

