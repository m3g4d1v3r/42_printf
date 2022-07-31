SRCS	= ft_printf.c \
		  ft_puthex_fd.c \
		  ft_putint_fd.c \
		  ft_putuint_fd.c \
		  ft_putptr_fd.c
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
