/*
** EPITECH PROJECT, 2022
** dante
** File description:
** astar_core
*/

#include "../include/my.h"

static t_lst *get_small_index(t_render *render, int *index)
{
    t_lst *tmp = render->open;
    t_lst *ret = NULL;
    int lowri = tmp->ori;
    int i = -1;

    while (tmp && ++i < 10) {
        if (tmp->ori <= lowri) {
            lowri = tmp->ori;
            ret = tmp;
            *index = i;
        }
        tmp = tmp->next;
    }
    return ret;
}

static t_lst *astar(t_render *render)
{
    int x = 0;
    int y = 0;
    int ind = 0;
    t_lst *min;
    t_lst *daddy;

    while (render->open) {
        min = get_small_index(render, &ind);
        x = min->x;
        y = min->y;
        render->cp_map[y][x] = 'C';
        daddy = create_elem(min->x, min->y, -1, min->bef);
        push_front(&render->close, daddy);
        if (x == render->end_x - 1 && y == render->end_y - 1)
            return daddy;
        render->open = my_node_pop(&render->open, ind);
        add_to_open(render, x, y, daddy);
    }
    return (NULL);
}

static void print_path(t_render *render, t_lst *daddy)
{
    render->map[0][0] = 'o';
    while (daddy && daddy->bef != NULL) {
        render->map[daddy->y][daddy->x] = 'o';
        daddy = daddy->bef;
    }
}

int astar_core(char **argv)
{
    t_render *render = init_struct(argv[1]);
    t_lst *daddy = astar(render);

    if (!daddy) {
        write(1, "no solution found", 17);
        return 84;
    } else {
        print_path(render, daddy);
        print_map(render->map, render);
    }
    return 0;
}
