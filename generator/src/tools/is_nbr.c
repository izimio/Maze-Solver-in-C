/*
** EPITECH PROJECT, 2022
** is_nbr
** File description:
** dante
*/

#include "header.h"

int is_nbr(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;
    while (str[i]) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}
