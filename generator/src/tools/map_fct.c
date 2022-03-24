/*
** EPITECH PROJECT, 2022
** map_fct
** File description:
** dante
*/

#include "header.h"

char **create_map(int y)
{
    char **map = malloc((y + 1) * sizeof(char *));

    map[y] = 0;
    return (map);
}

void free_map(char **map)
{
    int i = 0;

    while (map[i]) {
        free(map[i]);
        i++;
    }
    free(map[i]);
    free(map);
}

void display_map(char **map, bigstruct *big)
{
    int i = -1;

    while (map[++i]) {
        write(1, map[i], big->x);
        if (i != big->y - 1)
            write(1, "\n", 1);
    }
}
