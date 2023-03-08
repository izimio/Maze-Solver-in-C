##
## EPITECH PROJECT, 2022
## makefile
## File description:
## labmaker
##

CC = gcc

src = labmaker.c \
	src/generate_map.c \
	src/last_line.c \
	src/tools/display.c \
	src/tools/map_fct.c \
	src/tools/str_fct.c \
	src/tools/lk_list_fct.c \
	src/tools/is_nbr.c

NAME = generator

CFLAGS = -I./include -g3 -O3

CRIT_F = --coverage -lcriterion -I include

OBJ = ${src:.c=.o}

compile:	${OBJ}
	${CC} -o ${NAME} ${CFLAGS} ${OBJ}

all:	compile

clean:
	rm -rf ${OBJ}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

test_criterion_fclean:
	rm -f *gcno
	rm -f *gcda
	rm -f unit_tests

test_criterion: test_criterion_fclean
	gcc -o unit_tests src/*.c src/tools/*.c ../tests/test_generation.c ${CRIT_F}

tests_run: test_criterion
	./unit_tests

.PHONY: compile all clean fclean re
