/*
** EPITECH PROJECT, 2021
** tests
** File description:
** test_my_project.c
*/

#include "../generator/include/header.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(generate_lab, sadasd, .init = redirect_all_std)
{
    generate_lab(getnbr("50"), getnbr("50"), getnbr("-salut"));
}

Test(creat_tab, sadasd, .init = redirect_all_std)
{
    creat_tab(800);
}

Test(fill_line, sadasd, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 500);
    fill_line(str, 'd', 200);
}

Test(fill_line_alter, sadasd, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 500);
    fill_line_alter(str, 'd', 'p', 200);
}

Test(create_map, sadasd, .init = redirect_all_std)
{
    bigstruct *gi = malloc(sizeof(bigstruct));

    gi->y = 50;
    gi->x = 50;
    char **res = create_map(50);
    display_map(res, gi);
    free_map(res);
}

Test(create_elem, sadasd, .init = redirect_all_std)
{
    lk_list *elem = create_elem(0, 5);
    push_end(&elem, 4, 11);
    push_end(&elem, 4, 11);
    display_list(&elem);
    putnbr(-15);
    free_list(&elem);
}

Test(is_nbr, sadasd, .init = redirect_all_std)
{
    is_nbr("-salut");
    is_nbr("-45");
    is_nbr("78");
    dig_last_line(NULL, 1, 1, 0);
}
