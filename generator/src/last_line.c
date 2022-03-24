/*
** EPITECH PROJECT, 2022
** last_line
** File description:
** dante
*/

#include "header.h"

void dig_last_line(char **map, int y, int x, int perf)
{
    int i = y - 2;
    int random = rand() % x;

    if (y <= 2)
        return;
    for (int j = 0; j < x; map[i][j] = 'X', j++)
        ;
    for (; map[i - 1][random] != '*'; random = rand() % x)
        ;
    map[i][random] = '*';
    i += 1;
    for (int j = 0; j < x; map[i][j] = '*', j++)
        ;
    if (random > 0 && perf == 0)
        map[i][random - 1] = 'X';
}
