##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Project's main makefile
##

all :
		make -C./generator
		make -C./solver

clean:
		make clean -C./generator
		make clean -C./solver

fclean:
		make fclean -C./generator
		make fclean -C./solver

crit_fclean:
	make test_criterion_fclean -C ./generator
	make test_criterion_fclean -C ./solver

tests_run:
	make tests_run -C ./generator
	make tests_run -C ./solver

re:		fclean all

.PHONY: all clean fclean re
