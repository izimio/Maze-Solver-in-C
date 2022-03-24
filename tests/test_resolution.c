/*
** EPITECH PROJECT, 2021
** tests
** File description:
** test_my_project.c
*/

#include "../solver/include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_split, check_puchar, .init = redirect_all_std)
{
    char *str = "salut\nsalut\n\n\nsalut\n";
    my_split(str, "\n");
}

Test(check_lab, oui, .init = redirect_all_std)
{
    t_render *render = init_struct("../tests/map");
    check_lab(render, render->map_row, -1);
    print_map(render->map, render);
}

Test(astar_core, dddd, .init = redirect_all_std)
{
    char **res = my_split("./solver ../tests/map", " ");
    astar_core(res);
}

Test(astar_core, www, .init = redirect_all_std)
{
    char **res = my_split("./solver ../tests/mapw", " ");
    astar_core(res);
}

Test(push_front, lolilol, .init = redirect_all_std)
{
    t_lst *elem = NULL;
    t_lst *dd = create_elem(0, 0, 0, NULL);

    push_front(NULL, NULL);
    my_pushback(&elem, NULL);
    my_pushback(&dd, create_elem(0, 0, 0, NULL));
    my_pushback(&dd, create_elem(0, 0, 0, NULL));
    my_node_pop(&dd, 4);
}