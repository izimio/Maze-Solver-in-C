/*
** EPITECH PROJECT, 2022
** lk_list
** File description:
** dante
*/

#include "header.h"

lk_list *create_elem(int i, int j)
{
    lk_list *elem = malloc(sizeof(lk_list));

    elem->i = i;
    elem->j = j;
    elem->next = NULL;
    elem->prev = NULL;
    return (elem);
}

int push_end(lk_list **list, int i, int j)
{
    lk_list *temp = *list;
    lk_list *elem = create_elem(i, j);

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = elem;
    elem->prev = temp;
    return 0;
}

void free_list(lk_list **list)
{
    lk_list *tmp = (*list)->next;

    free(*list);
    if (tmp)
        free_list(&tmp);
}
