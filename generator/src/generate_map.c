/*
** EPITECH PROJECT, 2022
** generate_map
** File description:
** dante
*/

#include "header.h"

char **mine_map(bigstruct *big, int i)
{
    char **map = malloc((big->y + 1) * sizeof(char *));
    map[0] = malloc((big->x + 1) * sizeof(char));
    for (int j = 0; j < big->x; map[0][j] = '*', j++)
        ;
    map[0][big->x] = 0;
    map[big->y] = malloc((big->x + 1) * sizeof(char));
    for (; i <= big->y; i += 2) {
        map[i - 1] = malloc((big->x + 1) * sizeof(char));
        for (int j = 0; j < big->x; map[i - 1][j] = 'X', j++)
            ;
        map[i - 1][big->x] = 0;
        map[i] = malloc((big->x + 1) * sizeof(char));
        mine_portion(map, i, big);
        map[i][big->x] = 0;
    }
    dig_last_line(map, big->y, big->x, big->perf);
    map[big->y - 1][big->x - 1] = '*';
    if (big->x > 1)
        map[big->y - 1][big->x - 2] = '*';
    map[big->y] = 0;
    return (map);
}

int mine(char **map, int i, int j, int x)
{
    int chance = rand() % 100;

    map[i][j] = '*';
    if (chance < 50 || j + 2 >= x) {
        map[i][j + 1] = 'X';
        return (0);
    } else {
        map[i][j + 1] = '*';
        return (1);
    }
}

void mine_portion(char **map, int i, bigstruct *big)
{
    int compt = 1;
    int ind_rand;
    int chance;
    int j = 0;

    for (; j < big->x; j += 2) {
        for (; mine(map, i, j, big->x) == 1; compt++, j += 2)
            ;
        ind_rand = rand() % compt;
        map[i - 1][j - ind_rand * 2] = '*';
        compt = 1;
        if (big->perf == 0)
            map[i][j + 1] = (rand() % 100 < 50 ? '*' : map[i][j + 1]);
    }
}

void generate_lab(int x, int y, int perf)
{
    char **map;
    bigstruct *big = malloc(sizeof(bigstruct));

    srand(time(NULL));
    big->x = x;
    big->y = y;
    big->perf = perf;
    map = mine_map(big, 2);
    display_map(map, big);
    free_map(map);
    free(big);
}
