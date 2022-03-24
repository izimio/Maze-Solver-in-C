/*
** EPITECH PROJECT, 2022
** dante
** File description:
** astar_open
*/

#include "../include/my.h"

int calc_dist(t_render *render, int x, int y, int g)
{
    int val_x = my_abs(render->end_x - x);
    int val_y = my_abs(render->end_y - y);
    int h2 = 0;

    if (val_x > val_y)
        h2 = 14 * val_y + 10 * (val_x - val_y);
    else
        h2 = 14 * val_x + 10 * (val_y - val_x);
    return (g + h2);
}

int check_n_add_op(t_render *render, int x, int y, t_lst *daddy)
{
    if (x < 0 || x > render->end_x - 1 || y < 0 || y > render->end_y - 1)
        return 0;
    if (render->cp_map[y][x] && render->cp_map[y][x] == '*') {
        render->cp_map[y][x] = 'P';
        push_front(&render->open,
        create_elem(x, y, calc_dist(render, x, y, daddy->g), daddy));
        return 1;
    }
    return 0;
}

void add_to_open(t_render *render, int x, int y, t_lst *daddy)
{
    check_n_add_op(render, x, y + 1, daddy);
    check_n_add_op(render, x + 1, y, daddy);
    check_n_add_op(render, x - 1, y, daddy);
    check_n_add_op(render, x, y - 1, daddy);
}
