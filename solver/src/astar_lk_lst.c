/*
** EPITECH PROJECT, 2022
** dante
** File description:
** astar_lk_lst
*/

#include "../include/my.h"

t_lst *create_elem(int x, int y, int ori, t_lst *bef)
{
    t_lst *elem = malloc(sizeof(t_lst));

    elem->x = x;
    elem->y = y;
    if (!bef)
        elem->g = 0;
    else
        elem->g = bef->g + 1;
    elem->ori = ori;
    elem->bef = bef;
    elem->next = NULL;
    return elem;
}

void push_front(t_lst **lst, t_lst *new)
{
    if (!new || !lst)
        return;
    new->next = (*lst);
    (*lst) = new;
}

void my_pushback(t_lst **b_l, t_lst *elem)
{
    t_lst *tmp;

    if (!(*b_l)) {
        *b_l = elem;
        return;
    }
    tmp = *b_l;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = elem;
}

t_lst *my_node_pop(t_lst **begin_list, int nb)
{
    t_lst *tmp = *begin_list;
    t_lst *res = *begin_list;
    t_lst *prev = NULL;
    int i = 0;

    if (tmp && i == nb) {
        *begin_list = tmp->next;
        free(tmp);
        return (*begin_list);
    } else {
        while (tmp && i++ != nb) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (!tmp)
            return (NULL);
        prev->next = tmp->next;
        free(tmp);
    }
    return (res);
}
