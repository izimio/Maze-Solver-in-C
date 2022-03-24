/*
** EPITECH PROJECT, 2021
** ezredump
** File description:
** any_utils.c
*/

#include "../include/my.h"

void print_map(char **res, t_render *render)
{
    int i = -1;

    while (++i < render->end_y) {
        write(1, res[i], render->end_x);
        if (i != render->end_y - 1)
            write(1, "\n", 1);
    }
}

int my_abs(int a)
{
    return a < 0 ? -a : a;
}

t_render *init_struct(char *file)
{
    t_render *re = malloc(sizeof(t_render));

    re->map_row = get_content(file, re);
    re->end_y = 1;
    re->end_x = 0;
    check_lab(re, re->map_row, -1);
    re->map = better_splti(file, re);
    re->cp_map = better_splti(file, re);
    if (re->cp_map[0][0] && re->cp_map[0][0] == '*') {
        re->cp_map[0][0] = 'P';
        re->open = create_elem(0, 0, 0, NULL);
    } else
        re->open = NULL;
    re->close = NULL;
    if (!re->map)
        exit(84);
    if (re->map[0][0] != '*')
        exit(84);
    return re;
}
