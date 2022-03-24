/*
** EPITECH PROJECT, 2022
** str_fct
** File description:
** dante
*/

#include "header.h"

int getnbr(char *str)
{
    int res = 0;
    int signe = 1;
    int i = 0;

    if (str[0] == '-') {
        signe *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    return (res * signe);
}

char *creat_tab(int x)
{
    char *res = malloc((x + 1) * sizeof(char));

    res[x] = 0;
    return (res);
}

char *fill_line(char *str, char c, int x)
{
    int i = 0;

    while (i < x) {
        str[i] = c;
        i++;
    }
    return (str);
}

char *fill_line_alter(char *str, char c1, char c2, int x)
{
    int i = 0;

    while (i < x) {
        if (i % 2 == 0)
            str[i] = c1;
        else
            str[i] = c2;
        i++;
    }
    return (str);
}
