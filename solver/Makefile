##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## yo
##

SRCS = astar_main.c \
	src/astar_utils.c \
	src/astar_core.c\
	src/astar_lk_lst.c \
	src/astar_open.c \
	src/my_split.c \
	src/parse_file.c

OBJS = ${SRCS:.c=.o}

NAME = solver

CC = gcc

RM = rm -f

CRITERION_F = --coverage -lcriterion -I include

.c.o:
	${CC} -c $< -o ${<:.c=.o} -O3

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} -O3

all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

test_criterion_fclean:
	rm -f *gcno
	rm -f *gcda
	rm -f unit_tests

test_criterion: test_criterion_fclean
	gcc -o unit_tests src/*.c ../tests/test_resolution.c ${CRITERION_F}

tests_run: test_criterion
	./unit_tests

.PHONY: all clean fclean re
